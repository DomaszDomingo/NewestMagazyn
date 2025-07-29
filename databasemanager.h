#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include "part.h"
#include "location.h"
#include <QStandardPaths>
#include <QDir>
#include <optional>
#include <QDateTime>

struct HistoryEntry{
    QDateTime date;
    QString description;
    int quantityAfterChange;
};

class databaseManager
{
public:
    databaseManager();
    int getOrCreatePart (const Part & partData);//zwraca id częsci
    void addBatch(int partId, int quantity, double price); //dodaje partię
    bool addLocation (const Location & location);
    QList<Location> getAllLocations() const;
    bool deleteLocation (int LocationId);

    bool issuePartLIFO(int partId, int quantityToIssue);        //wydawanie LIFO
    bool issuePartFIFO(int partId, int quantityToIssue);        //wydawanie FIFO

    QList<Part> getAllParts() const;
    void updatePart (const Part & part, const QString &changeDescription);
    void deletePart (int id);
    std::optional<Part> getPartByCatalogNumber (const QString & catalogNumber) const;
    QList<QPointF> getQuantityHistoryForPart(int partId) const;
    QList <HistoryEntry> getDetailedHistoryForPart (int partId) const;

private:
    void openDatabase();
    void createTables();
    QSqlDatabase m_db;
    void logQuantityChange (int partId, int newQuantity, const QString &description);
};

#endif // DATABASEMANAGER_H
