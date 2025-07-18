#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include <QAbstractTableModel>
#include <QList>
#include "part.h"

class WarehouseManager : public QAbstractTableModel                 //Wykorzystano QAbstractTableModel, ponieważ łatwo dzięki tmeu liczyć kolumny/wiersze, pobierać dane itp.
{
    Q_OBJECT
public:
    //definiowanie kolumn przy pomocy enum
    enum Column{
        Name = 0,
        CatalogNumber,
        Quantity,
        Price,
        ColumnLocation,
        ColumnCount         // dzięki temu zawsze ile mam kolumn

    };

    explicit WarehouseManager(QObject *parent = nullptr);

    void addPart (const Part &part);

    //metody wymagane przez QAbstractTableModel. override typowe zastosowanie dla c++ czyli głównie zabezpieczenie zeby funkcja została odpowiednio wywołana.
    int rowCount (const QModelIndex &parent = QModelIndex()) const override;
    int columnCount (const QModelIndex &parent = QModelIndex()) const override;
    QVariant data (const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;



private:
    QList<Part> m_parts;
};

#endif // WAREHOUSEMANAGER_H
