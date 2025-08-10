#include "locationmanager.h"


LocationManager::LocationManager(databaseManager &dbManager, QObject *parent)
    : QAbstractTableModel(parent)
    ,m_dbManager (dbManager)

{
    m_locations = m_dbManager.getAllLocations();
    refreshData();

}

int LocationManager::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_locations.count();
}

int LocationManager::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return ColumnCount;
}

QVariant LocationManager::data(const QModelIndex &index, int role) const{


    if(!index.isValid() || role != Qt::DisplayRole){
        return QVariant();
    }

    const Location &location = m_locations.at(index.row());

        switch (index.column()){
        case Aisle:
            return location.aisle();
        case Rack:
            return location.rack();
        case Shelf:
            return location.shelf();
        default:
            return QVariant();
        }
}



QVariant LocationManager::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal){
        return QVariant();
    }

    switch (section){
    case Aisle:
        return "Alejka";
    case Rack:
        return "Regał";
    case Shelf:
        return "Półka";
    default:
        return QVariant ();
    }
}

void LocationManager::refreshData()
{
    beginResetModel();
    m_locations = m_dbManager.getAllLocations();
    endResetModel();
}

void LocationManager::deleteLocation(int row)
{
    if (row < 0 || row >= m_locations.count()){
        return;
    }
    beginRemoveRows(QModelIndex(), row, row);
    m_locations.removeAt(row);
    endRemoveRows();
}

Location LocationManager::getLocationAtIndex(const QModelIndex &index) const
{
    if(index.isValid() && index.row() < m_locations.count()){
            return m_locations.at(index.row());
    }
    return Location();
}




