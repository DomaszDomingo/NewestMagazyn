#ifndef PART_H
#define PART_H

#include <QString>
#include "location.h"

class Part
{
public:
    Part();
    Part(const QString &name, const QString &catalogNumber, int quantity, double price, const Location &location);
    const QString & name () const;
    const QString & catalogNumber () const;
    int quantity() const;
    double price () const;
    const Location & location () const;
    int id () const;
    void setId(int id);


    void setName (const QString &name);
    void setCatalogNumber (const QString &catalogNumber);
    void setQuantity (int quantity);
    void setPrice (double price);
    void setLocation (const Location & location);


private:
    QString m_name;
    QString m_catalogNumber;
    int m_quantity;
    double m_price;
    Location m_location;
    int m_id = -1;              //Domyślna wartość -1 oznacza, że obiekt nie jest w bazie
};

#endif // PART_H
