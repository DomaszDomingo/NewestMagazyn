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

void databaseManager::addPart(const Part &part)
{
    QSqlQuery query (m_db);
    query.prepare("INSERT INTO Parts (name, catalogNumber, quantity, price, locationAisle, locationRack, locationShelf) "
                  "VALUES (:name, :catalogNumber, :quantity, :price, :locationAisle, :locationRack, :locationShelf)");

    query.bindValue(":name", part.name());
    query.bindValue(":catalogNumber", part.catalogNumber());
    query.bindValue(":quantity", part.quantity());
    query.bindValue(":price",part.price());
    query.bindValue(":locationAisle",part.location().aisle());
    query.bindValue(":locationRack",part.location().rack());
    query.bindValue(":locationShelf",part.location().shelf());

    if(!query.exec()){
        qDebug() << "Błąd dodawania części" << query.lastError();
    } else {
        qDebug() <<"Funkcja addPart wykonana pomyślnie. Ilość dodanych rekordów:" << query.numRowsAffected();
    }
    int newPartId = query.lastInsertId().toInt();
    logQuantityChange(newPartId, part.quantity(), "Utworzenie nowej części");

}

QList<Part> databaseManager::getAllParts() const
{
    qDebug() << "Wywołanie getAllParts";

    QList<Part> parts;
    QSqlQuery query ("SELECT * FROM Parts", m_db);

    if(!query.exec()){
        qDebug() << "Błąd pobrania wszystkich części" << query.lastError();
    }

    while (query.next()){
        Part part;
        part.setId(query.value("id").toInt());
        part.setName(query.value("name").toString());
        part.setCatalogNumber(query.value("catalogNumber").toString());
        part.setQuantity(query.value("quantity").toInt());
        part.setPrice(query.value("price").toDouble());

        Location location (
            query.value("locationAisle").toString(),
            query.value("locationRack").toInt(),
            query.value("locationShelf").toInt());

        part.setLocation(location);

        parts.append(part);
    }

    qDebug() << "getAllParts zakończona. Znaleziono" << parts.count() << "części w bazie.";
    return parts;
}

void databaseManager::updatePart(const Part &part, const QString &changeDescription)
{
    QSqlQuery query (m_db);
    query.prepare("UPDATE Parts SET name = :name, catalogNumber = :catalogNumber, quantity = :quantity, "
                  "price = :price, locationAisle = :locationAisle, locationRack = :locationRack, "
                  "locationShelf = :locationShelf WHERE id = :id");

    query.bindValue(":name", part.name());
    query.bindValue(":catalogNumber", part.catalogNumber());
    query.bindValue(":quantity", part.quantity());
    query.bindValue(":price", part.price());
    query.bindValue(":locationAisle", part.location().aisle());
    query.bindValue(":locationRack", part.location().rack());
    query.bindValue(":locationShelf", part.location().shelf());
    query.bindValue(":id", part.id());

    if (!query.exec()) {
        qDebug() << "Błąd aktualizacji części:" << query.lastError();
    }

    logQuantityChange(part.id(),part.quantity(), changeDescription);
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
    query.prepare("SELECT * FROM Parts WHERE catalogNumber = :catalogNumber");
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
        part.setQuantity(query.value("quantity").toInt());
        part.setPrice(query.value("price").toDouble());

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
    QString createQuery = "CREATE TABLE IF NOT EXISTS Parts ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "name TEXT NOT NULL, "
                          "catalogNumber TEXT NOT NULL UNIQUE, "
                          "quantity INTEGER NOT NULL, "
                          "price REAL NOT NULL, "
                          "locationAisle TEXT, "
                          "locationRack INTEGER, "
                          "locationShelf INTEGER"
                          ");";

    QSqlQuery query (m_db);

    if(!query.exec(createQuery)){
        qDebug() << "Nie można utworzyć tabeli 'Parts':" << query.lastError();
    }else{
        qDebug() << "Tabela 'Parts' została utworzona lub już istnieje.";
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


