#ifndef ABSTRACTINCREMENTALID_H
#define ABSTRACTINCREMENTALID_H

#include "abstractid.h"

namespace obsolete
{

/** Podstawa dla wszystkich klas identyfikatorów automatycznych. **/
class AbstractIncrementalID : public AbstractID
{
public:
    inline AbstractIncrementalID(uint ID) : AbstractID(ID) {}    ///< Wykorzystuje konstruktor klasy nadrzędnej
    inline AbstractIncrementalID() {}                            ///< Pozwalam również na tworzenie niezainicjalizowanych obiektów.
protected:
private:
};

}

#endif // ABSTRACTINCREMENTALID_H
