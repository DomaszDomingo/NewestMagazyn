#include "updatepartinfooperation.h"



UpdatePartInfoOperation::UpdatePartInfoOperation(const Part &updatedPart)
    : m_part(updatedPart){}

bool UpdatePartInfoOperation::execute(databaseManager &dbManager)
{
    dbManager.updatePart(m_part, "Edycja danych poprzes operację");
    return true;
}

QString UpdatePartInfoOperation::getDescription() const
{
    return QString ("Aktualizacja danych dla cześci: '%1'").arg(m_part.name());
}


