#include "warehousemanager.h"


WarehouseManager::WarehouseManager(databaseManager & dbManager, QObject *parent)
    : QAbstractTableModel(parent)
    ,m_dbManager(dbManager)             // inicjalizacja referencji
{
    //od razu po stworzeniu obiektu, załaduj dane z bazy
    m_parts = m_dbManager.getAllParts();
}

void WarehouseManager::addPart(const Part &part)
{

    qDebug() << "WarehouseManager::add part wywołana. Resetowanie modelu...";
   //sygnały informujące widok, ze model zostanie całkowicie zresetowany
   beginResetModel();
   //odśwież listę częsći bezpośrednio z bazy danych
   m_parts = m_dbManager.getAllParts();
   //sygnał kończący resetowanie
   endResetModel();

}

void WarehouseManager::updatePart(const Part &part)
{
    for (int i = 0; i < m_parts.count(); ++i){
        if (m_parts.at(i).id() == part.id()){
            m_parts[i] = part;

            QModelIndex topLeft = index(i,0);
            QModelIndex bottomRight = index(i, ColumnCount - 1);
            emit dataChanged(topLeft,bottomRight);
            return;
        }
    }
}

void WarehouseManager::deletePart(int row)
{
    //sprawdzenie poprawności indeksu wiersza
    if (row < 0 || row >= m_parts.count()){
        return;
    }
    //informacja dla widokow, ze wiersze zostaną usunięte
    beginRemoveRows(QModelIndex(),row,row);

    //usuń element z wewnętrznej listy
    m_parts.removeAt(row);

    //zakończenie usuwania i odswieżenie widoku
    endRemoveRows();

}

void WarehouseManager::refreshData()
{
    beginResetModel();
    m_parts = m_dbManager.getAllParts();
    endResetModel();
}

QList<Part> WarehouseManager::getAllParts() const
{
    return m_parts;
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
        return "Ilość";
    case Price:
        return "Cena (PLN)";
    case ColumnLocation:
        return "Lokalizacja";
    default:
        return QVariant();
    }
}

Part WarehouseManager::getPartAtIndex(const QModelIndex &index) const
{
    //sprawdzenie poprawności
    if (index.isValid() && index.row() < m_parts.count()){
        return m_parts.at(index.row());
    }
    return Part();  //zwraca pusty obiekt jeśli indeks jest niepoprawny
}
