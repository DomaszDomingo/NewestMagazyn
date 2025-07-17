#include "warehousemanager.h"

WarehouseManager::WarehouseManager(QObject *parent) : QAbstractTableModel(parent)
{

}

void WarehouseManager::addPart(const Part &part)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());              //rowCount jest 2 razy, poniewaz za pierwszy to jest "first element"  w funkcji, a drugi to "last element". Umozliwia to dodawanie nastepnych elementów na koniec listy
    m_parts.append(part);
    endInsertRows();
}

int WarehouseManager::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
       return 0;
    return m_parts.count();
}

int WarehouseManager::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return ColumnCount;
}

QVariant WarehouseManager::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
            return QVariant();
        }
    const Part &part = m_parts.at(index.row());

    switch (index.column()) {
    case Name:
        return part.name();
    case CatalogNumber:
        return part.catalogNumber();
    case Quantity:
        return part.quantity();
    case Price:
        return QString::number(part.price(),'f',2);
    case ColumnLocation:
        return part.location().toString();
    default:
        return QVariant();
    }
}

QVariant WarehouseManager::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal){
        return QVariant();
    }

    switch (section){
    case Name:
        return "Nazwa części";
    case CatalogNumber:
        return "Numer katalogowy";
    case Quantity:
        return "Ilośc";
    case Price:
        return "Cena (PLN)";
    case ColumnLocation:
        return "Lokalizacja";
    default:
        return QVariant();
    }
}
