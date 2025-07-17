#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include <QAbstractTableModel>
#include <QList>
#include "part.h"

class WarehouseManager : public QAbstractTableModel
{
    Q_OBJECT
public:

    enum Column{
        Name = 0,
        CatalogNumber,
        Quantity,
        Price,
        ColumnCount
    };

    explicit WarehouseManager(QObject *parent = nullptr);

    void addPart (const Part &part);

    int rowCount (const QModelIndex &parent = QModelIndex()) const override;
    int columnCount (const QModelIndex &parent = QModelIndex()) const override;
    QVariant data (const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;



private:
    QList<Part> m_parts;
};

#endif // WAREHOUSEMANAGER_H
