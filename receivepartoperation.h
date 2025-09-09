#ifndef RECEIVEPARTOPERATION_H
#define RECEIVEPARTOPERATION_H

#include "databasemanager.h"
#include "warehousemanager.h"
#include "warehouseoperation.h"

class ReceivePartOperation : public WarehouseOperation{

public:
    ReceivePartOperation(int partId, int quantity, double price);

    bool execute (databaseManager & dbManager) override;
    QString getDescription() const override;

private:
    int m_partId;
    int m_quantity;
    double m_price;
};

#endif // RECEIVEPARTOPERATION_H
