#ifndef ABSTRACTIDGENERATOR_H
#define ABSTRACTIDGENERATOR_H

#include "abstractid.h"
#include "id.h"

namespace obsolete
{

/** Klasa bazowa obiektów-generatorów identyfikatorów. **/
class AbstractIDGenerator : public AbstractID
{
public:
    inline AbstractIDGenerator(uint ID=1) : AbstractID(ID) {}   ///< Inicjalizuje wartość początkową generatora identyfikatorów.
    virtual ID createID();                       ///< Tworzy nowy identyfikator.
    static ID createVoidID();                    ///< Tworzy niezainicjowany identyfikator
private:
};

}

#endif // ABSTRACTIDGENERATOR_H
