#include "recievepartoperation.h"


RecievePartOperation::RecievePartOperation(int partId, int quantity, double price)
{}

bool RecievePartOperation::execute(databaseManager &dbManager)
{
    dbManager.addBatch(m_partId, m_quantity, m_price);
    return true;
}

QString RecievePartOperation::getDescription() const
{
    return QString ("Przyjęcie partii: %1 szt. (cena: %2) dla części o ID: %3")
        .arg(m_quantity).arg(m_price).arg(m_partId);
}

