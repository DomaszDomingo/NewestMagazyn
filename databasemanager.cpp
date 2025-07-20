#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "part.h"
#include "location.h"


DatabaseManager::DatabaseManager() {

    openDatabase();                                                                                 //metoda otwierająca połączenie z bazą danych SQLite
    createTables();                                                                                 //metoda tworząca tabele 'Parts', chyba że już istnieje
}


//Dodawanie części, gdzie part to obiekt części do dodania
void DatabaseManager::addPart(const Part &part)
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
    }
}
//Odczytywanie wszystkich częsci z bazy danych. Zwraca liste obiektów Part
QList<Part> DatabaseManager::getAllParts() const
{
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
    return parts;
}


//aktualizacja części, parametrem są obiekty Part, z danymi (identyfikowanymi poprzez ID)
void DatabaseManager::updatePart(const Part &part)
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


//usuwanie części na podstawie ID
void DatabaseManager::deletePart(int id)
{
    QSqlQuery query (m_db);
    query.prepare("DELETE FROM Parts WHERE id = :id");
    query.bindValue(":id",id);

    if(!query.exec()){
        qDebug() << "Bład usuwania cześci: " << query.lastError();
    }

}


void DatabaseManager::openDatabase()
{

    //Dodanie bazy danych przy użyciu sterownika QSQLITE
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    //nadanie nazwy dla bazy danych
    m_db.setDatabaseName("warehouse.db");

    //weryfikacja otwarcia bazy danych
    if(!m_db.open()){

        qDebug() << "Błąd. Połączenie z bazą danych nieudane: " << m_db.lastError();
    }else{
        qDebug() << "Baza danych: Nawiązano połaczenie.";
    }

}

void DatabaseManager::createTables()

//Zapytanie SQL tworzące tabelę 'Parts'
// "IF NOT EXIST" zapobiega zdublowaniu tabeli.
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
    //Utworzenie obiektu QSqlQuery zeby wykonac zapytanie
    QSqlQuery query (m_db);


    //Weryfikacja wykonania zapytania
    if(!query.exec(createQuery)){
        qDebug() << "Nie można utworzyć tabeli 'Parts':" << query.lastError();
    }else{
        qDebug() << "Tabela 'Parts' została utworzona lub już istnieje.";
    }
}


