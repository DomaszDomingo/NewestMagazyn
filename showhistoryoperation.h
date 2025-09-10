#ifndef SHOWHISTORYOPERATION_H
#define SHOWHISTORYOPERATION_H
#include "warehouseoperation.h"

class ShowHistoryOperation : public WarehouseOperation
{
public:
    ShowHistoryOperation();

    explicit ShowHistoryOperation (const Part & part, QWidget * parentWidget);

    bool execute (databaseManager &dbManager) override;
    QString getDescription() const override;

private:
    Part m_partToShowHistory;
    QWidget *m_parent;
};

#endif // SHOWHISTORYOPERATION_H
