#ifndef MARKID_H
#define MARKID_H

#include "abstractincrementalid.h"

namespace obsolete
{

/** Klasa reprezentująca identyfikator oceny. **/
class MarkID : public AbstractIncrementalID
{
public:
    inline MarkID(uint ID) : AbstractIncrementalID(ID) {}    ///< Wykorzystuje konstruktor klasy nadrzędnej
    inline MarkID() {}                                       ///< Pozwalam również na tworzenie niezainicjalizowanych obiektów.
protected:
private:
};

}

#endif // MARKID_H
