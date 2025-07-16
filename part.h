#ifndef PART_H
#define PART_H

#include <QString>

class Part
{
public:
    Part();
    Part(const QString &name, const QString &catalogNumber, int quantity, double price);
    const QString & name () const;
    const QString & catalogNumber () const;
    int quantity() const;
    double price () const;

    void setName (const QString &name);
    void setCatalogNumber (const QString &catalogNumber);
    void setQuantity (int quantity);
    void setPrice (double price);

private:
    QString m_name;
    QString m_catalogNumber;
    int m_quantity;
    double m_price;
};

#endif // PART_H
