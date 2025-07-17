#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

databaseManager::databaseManager() {

    openDatabase();
    createTables();
}

void databaseManager::openDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_db.setDatabaseName("warehouse.db");

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


