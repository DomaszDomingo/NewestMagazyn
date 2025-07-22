#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include "part.h"
#include "location.h"
#include <QStandardPaths>
#include <QDir>
#include <optional>

class databaseManager
{
public:
    databaseManager();
    void addPart(const Part & part);
    QList<Part> getAllParts() const;
    void updatePart (const Part & part, const QString &changeDescription);
    void deletePart (int id);
    std::optional<Part> getPartByCatalogNumber (const QString & catalogNumber) const;
    QList<QPointF> getQuantityHistoryForPart(int partId) const;

private:
    void openDatabase();
    void createTables();
    QSqlDatabase m_db;
    void logQuantityChange (int partId, int newQuantity, const QString &changedescription);
};

#endif // DATABASEMANAGER_H
