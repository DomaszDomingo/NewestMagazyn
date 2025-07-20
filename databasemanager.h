#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include "part.h"
#include "location.h"

class DatabaseManager
{
public:
    DatabaseManager();
    void addPart(const Part & part);
    QList<Part> getAllParts() const;
    void updatePart (const Part & part);
    void deletePart (int id);


private:
    void openDatabase();
    void createTables();
    QSqlDatabase m_db;                                                      //obiekt reprezentujący połączenie z bazą danych
};

#endif // DATABASEMANAGER_H
