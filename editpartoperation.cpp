#include "editpartoperation.h"

EditPartOperation::EditPartOperation(const Part &updatedPartData)
    : m_updatedPartData(updatedPartData)
{
}

bool EditPartOperation::execute(databaseManager &dbManager)
{
    // Obiekt EditPartOperation przechowuje zaktualizowane dane części,
    // w tym jej ID. Wystarczy przekazać go do menedżera bazy danych.
    // Drugi argument to opis zmiany do historii - tworzymy go tutaj.
    QString changeDescription = "Edycja danych podstawowych.";
    dbManager.updatePart(m_updatedPartData, changeDescription);

    // Zakładamy, że operacja edycji zawsze się udaje, jeśli program działa poprawnie.
    // Można by dodać mechanizm zwracania błędu z dbManager, jeśli to konieczne.
    return true;
}

QString EditPartOperation::getDescription() const
{
    return QString("Edycja danych części: %1 (Nr kat: %2)")
        .arg(m_updatedPartData.name())
        .arg(m_updatedPartData.catalogNumber());
}
