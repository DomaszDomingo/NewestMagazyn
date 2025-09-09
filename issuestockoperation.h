#ifndef ISSUESTOCKOPERATION_H
#define ISSUESTOCKOPERATION_H

#include "warehouseoperation.h"
#include "part.h"

class IssueStockOperation : public WarehouseOperation
{
public:
    // Dodajemy enum do jednoznacznego określenia strategii
    enum class IssueStrategy {
        LIFO,
        FIFO
    };

    // Konstruktor teraz przyjmuje wybraną strategię
    explicit IssueStockOperation(const Part& partToIssue, int quantity, const QString& partName, IssueStrategy strategy);

    bool execute(databaseManager& dbManager) override;
    QString getDescription() const override;

private:
    int m_partId;
    int m_quantity;
    QString m_partName;
    IssueStrategy m_strategy; // Pole przechowujące strategię
};

#endif // ISSUESTOCKOPERATION_H
