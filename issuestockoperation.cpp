#include "issuestockoperation.h"

IssueStockOperation::IssueStockOperation(const Part &partToIssue, int quantity, const QString& partName, IssueStrategy strategy)
    : m_partId(partToIssue.id()),
    m_quantity(quantity),
    m_partName(partName),
    m_strategy(strategy) // Zapisujemy strategię
{
}

bool IssueStockOperation::execute(databaseManager &dbManager)
{

    switch (m_strategy) {
    case IssueStrategy::LIFO:
        return dbManager.issuePartLIFO(m_partId, m_quantity);
    case IssueStrategy::FIFO:
        return dbManager.issuePartFIFO(m_partId, m_quantity);
    }
    return false; // Domyślnie, na wypadek nieznanej strategii
}

QString IssueStockOperation::getDescription() const
{

    QString strategyStr = (m_strategy == IssueStrategy::LIFO) ? "LIFO" : "FIFO";
    return QString("Wydanie towaru (%1): %2, Ilość: %3")
        .arg(strategyStr)
        .arg(m_partName)
        .arg(m_quantity);
}
