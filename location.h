#ifndef LOCATION_H
#define LOCATION_H

#include <QString>

class Location
{
public:
    Location();
    Location(const QString &aisle, int rack, int shelf);


    const QString & aisle () const;
    int rack () const;
    int shelf () const;

    void setAisle (const QString &aisle);
    void setRack (int rack);
    void setShelf (int shelf);

    QString toString () const;

private:
    QString m_aisle;
    int m_rack;
    int m_shelf;

};

#endif // LOCATION_H
