#ifndef ABSTRACTID_H
#define ABSTRACTID_H

namespace obsolete
{

#include <QtCore/QtGlobal>
#include <QtCore/QDataStream>

/** Klasa bazowa dla wszystkich typów identyfikatorowych. **/
class AbstractID
{
    /** Zapisuje dany identyfikator do danego strumienia.
    * @param stream Strumień do którego będzie zapisany identyfikator.
    * @param ID Identyfikator który zostanie zapisany.
    * @return Ten sam strumień.
    **/
    friend QDataStream & operator<< (QDataStream& stream, const AbstractID& ID);

    /** Odczytuje dany identyfikator z danego strumienia.
    * @param stream Strumień z którego będzie odczytany identyfikator.
    * @param ID Identyfikator który zostanie zainicjalizowany odczytanymi danymi.
    * @return Ten sam strumień.
    **/
    friend QDataStream & operator>> (QDataStream& stream, AbstractID& ID);

public:
    /** Inicjalizuje nowy obiekt.
      * Użytkownik powinien użyć metody createdID().
      **/
    inline AbstractID ( uint ID=0 ) : ID ( ID ) {}

protected:
    uint        ID;                 ///< Reprezentowany ID
private:
};

/** Zapisuje dany identyfikator do danego strumienia.
  * @param stream Strumień do którego będzie zapisany identyfikator.
  * @param ID Identyfikator który zostanie zapisany.
  * @return Ten sam strumień.
  **/
QDataStream & operator<< (QDataStream& stream, const AbstractID& ID);

/** Odczytuje dany identyfikator z danego strumienia.
  * @param stream Strumień z którego będzie odczytany identyfikator.
  * @param ID Identyfikator który zostanie zainicjalizowany odczytanymi danymi.
  * @return Ten sam strumień.
  **/
QDataStream & operator>> (QDataStream& stream, AbstractID& ID);

}

#endif // ABSTRACTID_H
