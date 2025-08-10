#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H

#include <QAbstractTableModel>
#include "databasemanager.h"
#include "location.h"

class LocationManager : public QAbstractTableModel
{
    Q_OBJECT


public:
    //enum do zarządzania kolumnami
    enum Column {
        Aisle = 0,
        Rack,
        Shelf,
        ColumnCount
    };

    explicit LocationManager(databaseManager &dbManager, QObject *parent = nullptr);

    int rowCount (const QModelIndex &parent = QModelIndex()) const override;
    int columnCount (const QModelIndex &parent = QModelIndex()) const override;
    QVariant data (const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void refreshData();
    void deleteLocation (int row);
    Location getLocationAtIndex (const QModelIndex &index) const;

private:
    databaseManager & m_dbManager;
    QList<Location> m_locations;
};

#endif // LOCATIONMANAGER_H
