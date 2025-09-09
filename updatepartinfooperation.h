#ifndef UPDATEPARTINFOOPERATION_H
#define UPDATEPARTINFOOPERATION_H
#include "warehouseoperation.h"
#include "part.h"
#include "databasemanager.h"

class UpdatePartInfoOperation : public WarehouseOperation
{
public:
    UpdatePartInfoOperation(const Part & updatedPart);

    bool execute (databaseManager &dbManager) override;
    QString getDescription() const override;

private:
    Part m_part;
};

#endif // UPDATEPARTINFOOPERATION_H
