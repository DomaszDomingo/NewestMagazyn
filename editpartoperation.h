#ifndef EDITPARTOPERATION_H
#define EDITPARTOPERATION_H

#include "warehouseoperation.h"
#include "part.h"

class EditPartOperation : public WarehouseOperation
{
public:
    explicit EditPartOperation(const Part& updatedPartData);

    bool execute(databaseManager& dbManager) override;
    QString getDescription() const override;

private:
    Part m_updatedPartData;
};

#endif // EDITPARTOPERATION_H
