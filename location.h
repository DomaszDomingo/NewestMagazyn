#ifndef LOCATION_H
#define LOCATION_H

#include <QString>

// klasa reprezentuje fizyczną lokalizację części z magazynie. Przechowuje informację o alejce regale i półce
class Location
{
public:
    //konstruktor domyślny i parametryczny
    Location();
    Location(const QString &aisle, int rack, int shelf);


    const QString & aisle () const;
    int rack () const;
    int shelf () const;

    void setId (int id);
    void setAisle (const QString &aisle);
    void setRack (int rack);
    void setShelf (int shelf);


    QString toString () const;

private:
    QString m_aisle;
    int m_rack;
    int m_shelf;
    int m_id;

};

#endif // LOCATION_H
