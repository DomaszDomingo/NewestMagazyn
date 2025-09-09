#ifndef ISSUEPARTOPERATION_H
#define ISSUEPARTOPERATION_H
#include "warehouseoperation.h"
#include "databasemanager.h"

class IssuePartOperation : public WarehouseOperation {
public:
    enum class IssueMode {FIFO, LIFO};


    IssuePartOperation(int partId, int quantity, IssueMode mode);

    bool execute (databaseManager & dbManager) override;
    QString getDescription () const override;

private:
    int m_partId;
    int m_quantity;
    IssueMode m_mode;
};

#endif // ISSUEPARTOPERATION_H
