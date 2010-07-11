#ifndef EVENTID_H
#define EVENTID_H

#include "abstractincrementalid.h"

namespace obsolete
{

/** Klasa reprezentująca identyfikator zdarzenia. **/
class EventID : public AbstractIncrementalID
{
public:
    inline EventID(uint ID) : AbstractIncrementalID(ID) {}    ///< Wykorzystuje konstruktor klasy nadrzędnej
    inline EventID() {}                                       ///< Pozwalam również na tworzenie niezainicjalizowanych obiektów.
protected:
private:
};

}

#endif // EVENTID_H
