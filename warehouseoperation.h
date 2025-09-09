#ifndef WAREHOUSEOPERATION_H
#define WAREHOUSEOPERATION_H


#include <QString>
#include "databasemanager.h"

class WarehouseOperation
{
public:
    virtual ~WarehouseOperation () = default;

    virtual bool execute(databaseManager & dbManager) = 0;

    virtual QString getDescription () const = 0;
    WarehouseOperation();
};



#endif // WAREHOUSEOPERATION_H
