#ifndef LOCATION_H
#define LOCATION_H

#include <QString>


//klasa Location reprezentuje fizyczną lokalizację w magazynie.
class Location
{
public:
    Location();
    Location(const QString &aisle, int rack, int shelf);

    //gettery
    const QString & aisle () const;
    int rack () const;
    int shelf () const;

    //settery
    void setAisle (const QString &aisle);
    void setRack (int rack);
    void setShelf (int shelf);

    //metoda pomocnicza do konwesrji lokalizacji na tekst
    QString toString () const;

private:
    //zmienne wymagane zeby wykorzystać hermetyzację
    QString m_aisle;
    int m_rack;
    int m_shelf;

};

#endif // LOCATION_H
