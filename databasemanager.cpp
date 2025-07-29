#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "part.h"
#include "location.h"
#include <QPointF>


databaseManager::databaseManager() {

    openDatabase();
    createTables();
}

// Plik: databasemanager.cpp
int databaseManager::getOrCreatePart(const Part &partData)
{
    qDebug() << "Rozpoczynam getOrCreatePart dla numeru:" << partData.catalogNumber();
    auto existingPart = getPartByCatalogNumber(partData.catalogNumber());
    if (existingPart.has_value()) {
        qDebug() << "Część już istnieje. Zwracam ID:" << existingPart->id();
        return existingPart->id();
    }

    qDebug() << " Część nie istnieje. Próbuję stworzyć nowy rekord.";
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO Parts (name, catalogNumber, locationAisle, locationRack, locationShelf) "
                  "VALUES (:name, :catalogNumber, :locationAisle, :locationRack, :locationShelf)");

        query.bindValue(":name", partData.name());
    query.bindValue(":catalogNumber", partData.catalogNumber());
    query.bindValue(":locationAisle", partData.location().aisle());
    query.bindValue(":locationRack", partData.location().rack());
    query.bindValue(":locationShelf", partData.location().shelf());
    qDebug() << "Przygotowano zapytanie INSERT z danymi:" << partData.name() << partData.catalogNumber();

    // Diagnostyka
    if (query.exec()) {
        int newId = query.lastInsertId().toInt();
        qDebug() << "Dodano nową część. Nowe ID to:" << newId;
        return newId;
    } else {
        qDebug() << "Nie można wykonać zapytania INSERT.";
        qDebug() << "Błąd bazy danych:" << query.lastError().text();
        return -1; // Zwróć -1, aby zasygnalizować błąd
    }
}

void databaseManager::addBatch(int partId, int quantity, double price){
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO PartBatches (part_id, quantity, price_per_item, arrival_date) "
                                          "VALUES (:part_id, :quantity, :price, :date)");

    query.bindValue(":part_id",partId);
    query.bindValue(":quantity", quantity);
    query.bindValue(":price", price);
    query.bindValue(":date", QDateTime::currentDateTime().toString(Qt::ISODate));

    if(!query.exec()){
        qDebug() << "Błąd dodawania nowej partii: " << query.lastError();
        return;
    }

    QSqlQuery sumQuery(m_db);
    sumQuery.prepare("SELECT SUM(quantity) FROM PartBatches WHERE part_id = :id");
    sumQuery.bindValue(":id", partId);
    if (sumQuery.exec() && sumQuery.next()) {
        int newTotalQuantity = sumQuery.value(0).toInt();
        logQuantityChange(partId,newTotalQuantity, "Przyjęcie nowej partii");
    }
}

bool databaseManager::addLocation(const Location &location)
{
    QSqlQuery query (m_db);
    query.prepare("INSERT INTO Locations (aisle, rack, shelf) VALUES (:aisle, :rack, :shelf)");
    query.bindValue(":aisle", location.aisle());
    query.bindValue(":rack", location.rack());
    query.bindValue(":shelf", location.shelf());

    if(!query.exec()){
        qDebug () << "Bład dodawania lokalizacji:" << query.lastError();
        return false;
    }
    return true;
}

QList<Location> databaseManager::getAllLocations() const
{
    QList<Location> locations;
    QSqlQuery query ("SELECT id, aisle, rack, shelf FROM Locations ORDER BY aisle, rack, shelf",m_db);
    while (query.next()){
        Location loc (query.value("aisle").toString(),
                     query.value("rack").toInt(),
                     query.value("shelf").toInt());
        loc.setId(query.value("id").toInt());
        locations.append(loc);
    }
    return locations;
}

bool databaseManager::deleteLocation(int LocationId)
{
    QSqlQuery query (m_db);
    query.prepare("DELETE FROM Locations WHERE id = :id");
    query.bindValue(":id", LocationId);
    if (!query.exec()){
        qDebug() << "Błąd usuwania lokalizacji:" << query.lastError();
        return false;
    }
    return true;
}



bool databaseManager::issuePartLIFO(int partId, int quantityToIssue){

    if(!m_db.transaction()){ // Rozpocznij transakcję, aby wszystkie operacje były traktowane jako jedna całość.
        qDebug() << "Błąd rozpoczęcia transakcji:" << m_db.lastError();
        return false;
    }

    QSqlQuery query (m_db);
    query.prepare("SELECT id, quantity, arrival_date FROM PartBatches WHERE part_id = :part_id AND quantity > 0 ORDER BY arrival_date DESC");
    query.bindValue(":part_id",partId);

    //Sprawdzenie czy zapytanie zostało wykonane
    if(!query.exec()){
        qDebug() << "Błąd pobierania partii dla LIFO:" << query.lastError();
        m_db.rollback(); // wycofaj transakcję w razie błędu
        return false;
    }

    int remainingToIssue = quantityToIssue;
    QStringList issueDetails;   // lista do przechowywania szczegółów wydania

    while (query.next() && remainingToIssue > 0){
        int batchId = query.value(0).toInt();
        int batchQuantity = query.value(1).toInt();
        QDateTime arrivalDate = QDateTime::fromString(query.value(2).toString(), Qt::ISODate);
        int quantityFromThisBatch = qMin(remainingToIssue,batchQuantity);
        issueDetails.append(QString(" - %1 szt. (partia z %2)").arg(quantityFromThisBatch).arg(arrivalDate.toString("dd.MM.yyyy HH:mm")));

        QSqlQuery updateQuery (m_db);
        if(batchQuantity > quantityFromThisBatch ){
            //jeśli partia nie zostanie wyczerpana, aktualizuj jej ilość
            updateQuery.prepare("UPDATE PartBatches SET quantity = quantity - :issued WHERE id = :id");
            updateQuery.bindValue(":issued", quantityFromThisBatch);
        } else {
            //jeśli partia zostanie wyczerpana, usun ją
            updateQuery.prepare("DELETE FROM PartBatches WHERE id = :id");
        }

        updateQuery.bindValue(":id", batchId);

        if(!updateQuery.exec()){
            m_db.rollback();
            return false;
        }
        remainingToIssue -= quantityFromThisBatch;
    }
    //Sprawdz czy udało sie wydać ządaną ilosć.
    if(remainingToIssue > 0){   // nie udało się wydać wszystkiego
        qDebug() << "Nie udało się wydać całości - brak wystarczającej ilości na stanie.";
        m_db.rollback();
        return false;
    }

    //jesli wszystko ok, zaloguj zmiane i zatwierdz transakcję
    QList<Part> allParts = getAllParts();
    int newTotalQuantity = 0;
    for (const Part &p : allParts){
       if(p.id() == partId){
            newTotalQuantity = p.quantity();
            break; // znaleziono częśc, mozna przerwać pętlę
        }
    }


    if (m_db.commit()){
        QString fullDescription = QString ("Wydanie LIFO (%1 szt.):\n%2")
                                      .arg(quantityToIssue)
                                      .arg(issueDetails.join("\n"));

        QSqlQuery sumQuery (m_db);
        sumQuery.prepare("SELECT COALESCE(SUM (quantity), 0) FROM PartBatches WHERE  part_id = :id");
        sumQuery.bindValue(":id", partId);
        int newTotalQuantity = 0;
        if (sumQuery.exec() && sumQuery.next()){
            newTotalQuantity = sumQuery.value(0).toInt();
        }
        logQuantityChange(partId,newTotalQuantity, fullDescription);
        return true;
    } else
        return false;
}


bool databaseManager::issuePartFIFO(int partId, int quantityToIssue){

    if(!m_db.transaction()){ // Rozpocznij transakcję, aby wszystkie operacje były traktowane jako jedna całość.
        qDebug() << "Błąd rozpoczęcia transakcji:" << m_db.lastError();
        return false;
    }

    QSqlQuery query (m_db);
    query.prepare("SELECT id, quantity, arrival_date FROM PartBatches WHERE part_id = :part_id AND quantity > 0 ORDER BY arrival_date ASC");
    query.bindValue(":part_id",partId);

    //Sprawdzenie czy zapytanie zostało wykonane
    if(!query.exec()){
        qDebug() << "Błąd pobierania partii dla LIFO:" << query.lastError();
        m_db.rollback(); // wycofaj transakcję w razie błędu
        return false;
    }

    int remainingToIssue = quantityToIssue;
    QStringList issueDetails;

    while (query.next() && remainingToIssue > 0){
        int batchId = query.value(0).toInt();
        int batchQuantity = query.value(1).toInt();
        QDateTime arrivalDate = QDateTime::fromString(query.value(2).toString(), Qt::ISODate);
        int quantityFromThisBatch = qMin(remainingToIssue,batchQuantity);

        issueDetails.append(QString(" - %1 szt. (partia z %2)").arg(quantityFromThisBatch).arg(arrivalDate.toString("dd.MM.yyyy HH:mm")));

        QSqlQuery updateQuery (m_db);
        if(batchQuantity > quantityFromThisBatch ){
            //jeśli partia nie zostanie wyczerpana, aktualizuj jej ilość
            updateQuery.prepare("UPDATE PartBatches SET quantity = quantity - :issued WHERE id = :id");
            updateQuery.bindValue(":issued", quantityFromThisBatch);
        } else {
            //jeśli partia zostanie wyczerpana, usun ją
            updateQuery.prepare("DELETE FROM PartBatches WHERE id = :id");
        }
        updateQuery.bindValue(":id", batchId);

        if(!updateQuery.exec()){
            m_db.rollback();
            return false;
        }
        remainingToIssue -= quantityFromThisBatch;
    }
    //Sprawdz czy udało sie wydać ządaną ilosć.
    if(remainingToIssue > 0){   // nie udało się wydać wszystkiego
        qDebug() << "Nie udało się wydać całości - brak wystarczającej ilości na stanie.";
        m_db.rollback();
        return false;
    }

    //jesli wszystko ok, zaloguj zmiane i zatwierdz transakcję
    QList<Part> allParts = getAllParts();
    int newTotalQuantity = 0;
    for (const Part &p : allParts){
        if(p.id() == partId){
            newTotalQuantity = p.quantity();
            break; // znaleziono częśc, mozna przerwać pętlę
        }
     }


    if (m_db.commit()){
        QString fullDescription = QString ("Wydanie FIFO (%1 szt.):\n%2")
                                      .arg(quantityToIssue)
                                      .arg(issueDetails.join("\n"));

        QSqlQuery sumQuery (m_db);
        sumQuery.prepare("SELECT COALESCE(SUM (quantity), 0) FROM PartBatches WHERE  part_id = :id");
        sumQuery.bindValue(":id", partId);
        int newTotalQuantity = 0;
        if (sumQuery.exec() && sumQuery.next()){
            newTotalQuantity = sumQuery.value(0).toInt();
        }
        logQuantityChange(partId,newTotalQuantity, fullDescription);
        return true;
    }
    m_db.rollback();
    return false;
}

QList<Part> databaseManager::getAllParts() const
{
    QList<Part> parts;

    // Zapytanie, które łączy Parts z sumą ilości z PartBatches
    QSqlQuery mainQuery("SELECT p.id, p.name, p.catalogNumber, p.locationAisle, p.locationRack, p.locationShelf, "
                        "COALESCE(SUM(b.quantity), 0) as total_quantity "
                        "FROM Parts p LEFT JOIN PartBatches b ON p.id = b.part_id "
                        "GROUP BY p.id", m_db);

    if (!mainQuery.exec()) {
        qDebug() << "Błąd pobierania wszystkich części:" << mainQuery.lastError();
        return parts;
    }

    while (mainQuery.next()) {
        Part part;
        int currentPartId = mainQuery.value("id").toInt();
        part.setId(currentPartId);

        part.setId(mainQuery.value("id").toInt());
        part.setName(mainQuery.value("name").toString());
        part.setCatalogNumber(mainQuery.value("catalogNumber").toString());

        Location location(
            mainQuery.value("locationAisle").toString(),
            mainQuery.value("locationRack").toInt(),
            mainQuery.value("locationShelf").toInt()
            );
        part.setLocation(location);

        part.setQuantity(mainQuery.value("total_quantity").toInt());


        //dodatkowe zapytanie o cene, bo bez tego nie działało
        QSqlQuery priceQuery(m_db);
        priceQuery.prepare("SELECT price_per_item FROM PartBatches "
                           "WHERE part_id = :id ORDER BY arrival_date DESC LIMIT 1");
        priceQuery.bindValue(":id", currentPartId);
        if (priceQuery.exec() && priceQuery.next()) {
            part.setPrice(priceQuery.value(0).toDouble());
        } else {
            part.setPrice(0.0); // Ustaw cenę na 0, jeśli nie ma żadnych partii
        }

        parts.append(part);
    }
    return parts;
}

void databaseManager::updatePart(const Part &part, const QString &changeDescription)
{
    QSqlQuery query (m_db);
    query.prepare("UPDATE Parts SET name = :name, catalogNumber = :catalogNumber, locationAisle = :locationAisle, "
                  "locationRack = :locationRack, locationShelf = :locationShelf WHERE id = :id");

    // Bindowanie tylko istniejących danych
    query.bindValue(":name", part.name());
    query.bindValue(":catalogNumber", part.catalogNumber());
    query.bindValue(":locationAisle", part.location().aisle());
    query.bindValue(":locationRack", part.location().rack());
    query.bindValue(":locationShelf", part.location().shelf());
    query.bindValue(":id", part.id());


    if (!query.exec()) {
        qDebug() << "Błąd aktualizacji części:" << query.lastError();
    }

}

void databaseManager::deletePart(int id)
{
    QSqlQuery query (m_db);
    query.prepare("DELETE FROM Parts WHERE id = :id");
    query.bindValue(":id",id);

    if(!query.exec()){
        qDebug() << "Bład usuwania cześci: " << query.lastError();
    }

}

std::optional<Part> databaseManager::getPartByCatalogNumber(const QString &catalogNumber) const
{
    QSqlQuery query(m_db);
    query.prepare("SELECT id, name, catalogNumber, locationAisle, locationRack, locationShelf "
                  "FROM Parts WHERE catalogNumber = :catalogNumber");
    query.bindValue(":catalogNumber", catalogNumber);

    if(!query.exec()){
        qDebug() << "Błąd wyszukania cześci po numerze katalogowym" << query.lastError();
        return std::nullopt; //zwróć pusty optional w razie błędu
    }
    //sprawdz czy znaleziono jakikolwiek rekord
    if(query.next()){
        //Znaleziono część - stworz obiekt i go zwróć
        Part part;
        part.setId(query.value("id").toInt());
        part.setName(query.value("name").toString());
        part.setCatalogNumber(query.value("catalogNumber").toString());

        Location location (
            query.value("locationAisle").toString(),
            query.value("locationRack").toInt(),
            query.value("locationShelf").toInt()
            );
        part.setLocation(location);

        return part;

    }
    //Nie znaleziono części
    return std::nullopt;
}

QList<QPointF> databaseManager::getQuantityHistoryForPart(int partId) const
{
    QList<QPointF> history;
    QSqlQuery query (m_db);

    query.prepare("SELECT change_date, quantity_after_change FROM QuantityHistory "
                  "WHERE part_id = :part_id ORDER BY change_date ASC");

    query.bindValue(":part_id", partId);

    if(!query.exec()){
        qDebug() << "Błąd pobierania historii ilości: " << query.lastError();
        return history;
    }

    while (query.next()){
        QDateTime date = QDateTime::fromString(query.value(0).toString(), Qt::ISODate);
        double quantity = query.value(1).toDouble();
        history.append(QPointF(date.toMSecsSinceEpoch(), quantity));
    }
    return history;
}

QList<HistoryEntry> databaseManager::getDetailedHistoryForPart(int partId) const
{
    QList <HistoryEntry> history;
    QSqlQuery query (m_db);
    query.prepare("SELECT change_date, change_description, quantity_after_change FROM QuantityHistory "
                   "WHERE part_id = :part_id ORDER BY change_date DESC"); // sortowanie od najnowszych

    query.bindValue(":part_id", partId);

    if(!query.exec()){
        qDebug() << "Bład pobierania szczegółowej historii: " << query.lastError();
        return history;
    }

    while (query.next()){
        HistoryEntry entry;
        entry.date = QDateTime::fromString(query.value(0).toString(),Qt::ISODate);
        entry.description = query.value(1).toString();
        entry.quantityAfterChange = query.value(2).toInt();
        history.append(entry);

    }
    return history;
}

void databaseManager::openDatabase()
{
    //ustawienie standardowego folderu dla danych aplikacji
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    QDir dir (dataPath);

    //tworzenie folderu jeżeli nie istnieje
    if(!dir.exists()){
        dir.mkpath("."); // kropka ozncza utworzenie ścieżki zdefiniowanej w "dir"
    }

    //Połączenie scieżki do folderu z nazwa pliku bazy danych

    QString dbPath = dataPath + "/warehouse.db";
    qDebug() << "Ścieżka bazy danych: " << dbPath; // wyświetlenie ściezki

    m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_db.setDatabaseName(dbPath);

    if(!m_db.open()){
        qDebug() << "Błąd. Połączenie z bazą danych nieudane: " << m_db.lastError();
    }else{
        qDebug() << "Baza danych: Nawiązano połaczenie.";
    }

}

void databaseManager::createTables()
{
    QSqlQuery query(m_db);

    // Migracja (jeśli tabela 'Parts_old' jeszcze nie istnieje, co oznacza, że migracja nie była robiona)
    query.exec("ALTER TABLE Parts RENAME TO Parts_old;");

    // Krok 2: Tworzenie tabel z klauzulą IF NOT EXISTS
    QString createPartsQuery = "CREATE TABLE IF NOT EXISTS Parts ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "name TEXT NOT NULL, "
                               "catalogNumber TEXT NOT NULL UNIQUE, "
                               "locationAisle TEXT, locationRack INTEGER, locationShelf INTEGER);";
    if(!query.exec(createPartsQuery)){
        qDebug() << "Błąd Tworzenia tabeli Parts:" << query.lastError();
    }

    QString createBatchesQuery = "CREATE TABLE IF NOT EXISTS PartBatches ("
                                 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "part_id INTEGER NOT NULL, "
                                 "quantity INTEGER NOT NULL, "
                                 "price_per_item REAL NOT NULL, " // Zmieniono na REAL
                                 "arrival_date TEXT NOT NULL, "
                                 "FOREIGN KEY (part_id) REFERENCES Parts(id) ON DELETE CASCADE);"; // Poprawiono part_id
    if (!query.exec(createBatchesQuery)){
        qDebug() << "Błąd tworzenia tabeli PartBatches: " << query.lastError();
    }

    QString createHistoryQuery = "CREATE TABLE IF NOT EXISTS QuantityHistory ("
                                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "part_id INTEGER NOT NULL,"
                                "change_date TEXT NOT NULL,"
                                "quantity_after_change INTEGER NOT NULL, "
                                "change_description TEXT, "
                                "FOREIGN KEY (part_id) REFERENCES Parts(id) ON DELETE CASCADE"
                                ");";
    QSqlQuery historyQuery (m_db);
    if(!historyQuery.exec(createHistoryQuery)){
        qDebug() << "Nie można utworzyć tabeli 'QuantityHistory':" << historyQuery.lastError();
    } else {
        qDebug() << "Tabela 'QuantityHistory' została utworzona lub już istnieje. ";
    }

    QString createLocationsQuery = "CREATE TABLE IF NOT EXISTS Locations ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                   "aisle TEXT NOT NULL , "
                                   "rack INTEGER NOT NULL, "
                                   "shelf INTEGER NOT NULL, "
                                   "UNIQUE (aisle, rack, shelf)" // zapobiega duplikatom
                                   ");";

    if (!query.exec(createBatchesQuery)){
        qDebug() << "Błąd tworzenia tabeli locations:" << query.lastError();
    }
}


void databaseManager::logQuantityChange(int partId, int newQuantity, const QString &description)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO QuantityHistory (part_id, change_date, quantity_after_change, change_description)"
                  "VALUES (:part_id, :date, :quantity, :description)");

    query.bindValue(":part_id", partId);
    query.bindValue(":date", QDateTime::currentDateTime().toString(Qt::ISODate));
    query.bindValue(":quantity", newQuantity);
    query.bindValue(":description", description);

    if(!query.exec()){
        qDebug() << "Błąd logowania historii ilości:" << query.lastError();
    }
}


