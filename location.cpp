#include "location.h"

Location::Location() :
    m_rack(0), m_shelf (0), m_id(-1)
{}

Location::Location(const QString &aisle, int rack, int shelf) : m_aisle(aisle),
    m_rack(rack),
    m_shelf(shelf),
    m_id(-1)
{}

const QString &Location::aisle() const
{
    return m_aisle;
}

int Location::rack() const
{
    return m_rack;
}

int Location::shelf() const
{
    return m_shelf;
}

int Location::id() const
{
    return m_id;
}

void Location::setId(int id)
{
    m_id = id;
}

void Location::setAisle(const QString &aisle)
{
    m_aisle = aisle;
}

void Location::setRack(int rack)
{
    m_rack = rack;
}

void Location::setShelf(int shelf)
{
    m_shelf = shelf;
}

QString Location::toString() const
{
    return QString("%1-%2-%3")
        .arg(m_aisle)
        .arg(m_rack,2,10,QChar('0'))
        .arg(m_shelf,2,10,QChar('0'));
}
