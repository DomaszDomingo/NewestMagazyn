#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include <QAbstractTableModel>
#include <QList>
#include "part.h"
#include "databasemanager.h"

class WarehouseManager : public QAbstractTableModel
{
    Q_OBJECT
public:



    enum Column{
        Name = 0,
        CatalogNumber,
        Quantity,
        Price,
        ColumnLocation,
        ColumnCount

    };

    explicit WarehouseManager(databaseManager & dbManager, QObject *parent = nullptr);

    void addPart (const Part &part);
    void updatePart (const Part & part);
    void deletePart (int row);
    void refreshData();
    QList <Part> getAllParts() const;
    Part getPartById(int id) const;
    int rowCount (const QModelIndex &parent = QModelIndex()) const override;
    int columnCount (const QModelIndex &parent = QModelIndex()) const override;
    QVariant data (const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Part getPartAtIndex (const QModelIndex & index) const;



private:
    databaseManager& m_dbManager;
    QList<Part> m_parts;
};

#endif // WAREHOUSEMANAGER_H
