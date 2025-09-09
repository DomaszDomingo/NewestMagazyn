#ifndef RECIEVEPARTOPERATION_H
#define RECIEVEPARTOPERATION_H

#include "databasemanager.h"
#include "warehousemanager.h"
#include "warehouseoperation.h"

class RecievePartOperation : public WarehouseOperation{

public:
    RecievePartOperation(int partId, int quantity, double price);

    bool execute (databaseManager & dbManager) override;
    QString getDescription() const override;

private:
    int m_partId;
    int m_quantity;
    double m_price;
};

#endif // RECIEVEPARTOPERATION_H
