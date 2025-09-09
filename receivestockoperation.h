#ifndef RECEIVESTOCKOPERATION_H
#define RECEIVESTOCKOPERATION_H

#include "warehouseoperation.h"
#include "part.h"

class ReceiveStockOperation : public WarehouseOperation
{
public:
    explicit ReceiveStockOperation(const Part& partData);

    bool execute(databaseManager& dbManager) override;
    QString getDescription() const override;

private:
    Part m_partData;
};

#endif // RECEIVESTOCKOPERATION_H
