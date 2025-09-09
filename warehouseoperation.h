#ifndef WAREHOUSEOPERATION_H
#define WAREHOUSEOPERATION_H

#include <QString>
#include <QDateTime>
#include "databasemanager.h"

class WarehouseOperation
{
public:
    // DEKLARACJA konstruktora (bez ciała)
    WarehouseOperation();

    // DEKLARACJA wirtualnego destruktora (bez ciała)
    virtual ~WarehouseOperation();

    // Metody czysto wirtualne pozostają bez zmian
    virtual bool execute(databaseManager& dbManager) = 0;
    virtual QString getDescription() const = 0;

    // Prosty getter może pozostać zdefiniowany w nagłówku (jest inline)
    QDateTime getTimestamp() const { return m_timestamp; }

protected:
           // Przeniesiono do pliku .cpp

private:
    QDateTime m_timestamp;
};

#endif // WAREHOUSEOPERATION_H
