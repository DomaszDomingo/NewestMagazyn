#include "issuepartoperation.h"


IssuePartOperation::IssuePartOperation(int partId, int quantity, IssueMode mode)
{

}

bool IssuePartOperation::execute(databaseManager &dbManager)
{
    if(m_mode == IssueMode::FIFO){
        return dbManager.issuePartFIFO(m_partId, m_quantity);
    } else {
        return dbManager.issuePartLIFO(m_partId,m_quantity);
    }
}

QString IssuePartOperation::getDescription() const
{
    QString modeStr = (m_mode == IssueMode::FIFO) ? "FIFO" : "LIFO";
    return QString ("Wydanie (%1): %2 szt. dla części o ID: %3")
        .arg(modeStr).arg(m_quantity).arg(m_partId);
}



