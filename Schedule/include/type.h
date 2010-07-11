#ifndef TYPE_H
#define TYPE_H

#include <QtCore/QString>

#include "initializable.h"
#include "deletable.h"

/** Reprezentuje dany typ wydarzenia. Wydarzenie musi zostać ustawione zanim pojawi się.
  * 
  * Jest to klasa w stylu Utility. Składa się w szczególności z:
  * - Wagi tego typu wydarzeń (ala mnożnik do ocen powstałych poprzez wydarzenie tego typu).
  * - Skali ocen i zasad oceniania.
  * - Metod do prostej i szybkiej transformacji oceny (Mark) w ocene cząstkową (uwzględniając format ocen tego typu).
*/
class Type : private Initializable, private Deletable
{
public:
private:
    QString name;               ///< Nazwa typu
public:
    /** Konstruktor. Inicjalizuje dany Typ wydarzenia.
      * @param name Nazwa danego Typu wydarzenia
      */
    Type(QString name) : name(name), Initializable(true), Deletable(false) {}
    
    /** Konstruktor. Pozwala na tworzenie niezainicjalizowanych obiektów. */
    Type() : Initializable(false), Deletable(false) {}
    
    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const Type &o) const
    {
        return Initializable(*this)==Initializable(o) && Deletable(*this)==Deletable(o) && name==o.name;
    }
    
private:
};

#endif // TYPE_H
