#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "part.h"
#include "location.h"


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
    query.bindValue("locationAisle",part.location().aisle());
    query.bindValue("locationRack",part.location().rack());
    query.bindValue(":locationShelf",part.location().shelf());

    if(!query.exec()){
        qDebug() << "Błąd dodawania części" << query.lastError();
    } else {
        qDebug() <<"Funkcja addPart wykonana pomyślnie. Ilość dodanych rekordów:" << query.numRowsAffected();
    }


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

void databaseManager::updatePart(const Part &part)
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
}


