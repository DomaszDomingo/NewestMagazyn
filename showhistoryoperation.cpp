#include "showhistoryoperation.h"
#include "historydialog.h"
#include <QList>

ShowHistoryOperation::ShowHistoryOperation(const Part &part, QWidget * parentWidget)
    : m_partToShowHistory(part), m_parent(parentWidget)
{}

bool ShowHistoryOperation::execute(databaseManager & dbManager)
{
    QList<HistoryEntry> history = dbManager.getDetailedHistoryForPart(m_partToShowHistory.id());

    if (!history.isEmpty()){
        HistoryDialog dialog (m_partToShowHistory.name(), history, m_parent);
        dialog.exec();
    } else {
        return false;
    }
    return true;
}

QString ShowHistoryOperation::getDescription() const
{
    return QString ("Wyświetlono historię dla części: %1").arg(m_partToShowHistory.name());
}


