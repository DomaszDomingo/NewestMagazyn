#include "receivestockoperation.h"

ReceiveStockOperation::ReceiveStockOperation(const Part &partData)
    : m_partData(partData)
{
}

bool ReceiveStockOperation::execute(databaseManager &dbManager)
{
    // Logika, która wcześniej była w MainWindow, teraz jest tutaj
    int partId = dbManager.getOrCreatePart(m_partData);
    if (partId != -1) {
        dbManager.addBatch(partId, m_partData.quantity(), m_partData.price());
        return true;
    }
    return false;
}

QString ReceiveStockOperation::getDescription() const
{
    return QString("Przyjęcie towaru: %1 (Nr kat: %2), Ilość: %3, Cena: %4")
        .arg(m_partData.name())
        .arg(m_partData.catalogNumber())
        .arg(m_partData.quantity())
        .arg(QString::number(m_partData.price(), 'f', 2));
}
