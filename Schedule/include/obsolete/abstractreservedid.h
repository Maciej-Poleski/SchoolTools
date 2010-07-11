#ifndef ABSTRACTRESERVEDID_H
#define ABSTRACTRESERVEDID_H

#include "abstractid.h"

namespace obsolete
{

/** Klasa reprezentująca identyfikatory rezerwowane z góry. (coś w stylu haszowanie doskonałe) **/
class AbstractReservedID : public AbstractID
{
public:
    inline AbstractReservedID(uint ID) : AbstractID(ID) {}      ///< Wykorzystuje konstruktor klasy nadrzędnej.
    inline AbstractReservedID() {}                              ///< Pozwalam również na tworzenie niezainicjalizowanych obiektów.
    /** Opakowuje numer porządkowy zadaną liczbą. **/
    inline static AbstractReservedID createID ( uint ID );
private:
};

}

#endif // ABSTRACTRESERVEDID_H
