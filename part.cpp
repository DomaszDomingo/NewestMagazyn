#include "part.h"

Part::Part() : m_quantity(0), m_price(0.0)
{

}

Part::Part(const QString &name, const QString &catalogNumber, int quantity, double price, const Location & location) : m_name(name),
    m_catalogNumber(catalogNumber),
    m_quantity(quantity),
    m_price(price),
    m_location(location)
{

}

const QString &Part::name() const
{
    return m_name;
}

const QString &Part::catalogNumber() const
{
    return m_catalogNumber;
}

int Part::quantity() const
{
    return m_quantity;
}

double Part::price() const
{
    return m_price;
}

const Location &Part::location() const
{
    return m_location;
}

int Part::id() const
{
    return m_id;
}

void Part::setId(int id)
{
    m_id = id;
}

void Part::setName(const QString &name)
{
    m_name = name;
}

void Part::setCatalogNumber(const QString &catalogNumber)
{
    m_catalogNumber = catalogNumber;
}

void Part::setQuantity(int quantity)
{
    m_quantity = quantity;
}

void Part::setPrice(double price)
{
    m_price = price;
}

void Part::setLocation(const Location &location)
{
    m_location = location;
}

