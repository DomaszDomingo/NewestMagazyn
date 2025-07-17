#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class databaseManager
{
public:
    databaseManager();

private:
    void openDatabase();

    void createTables();

    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
