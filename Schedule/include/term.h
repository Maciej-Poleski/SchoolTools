#ifndef TERM_H
#define TERM_H

#include <QtCore/QDate>

#include "initializable.h"
#include "idgenerator.h"

/** Reprezentacja egzekucji wydarzenia. Jest również odnośnikiem do danego wydarzenia.
  * 
  * Skutkuje oceną (Mark), chyba że został odwołany (revoke).
  * Składa się z:
  * - Identyfikatora wydarzenia związanego z tym terminem.
  * - Identyfikatora oceny - skutku tego terminu (chyba że [revoke]).
  * - Wyjątkowej skali ocen i zasad oceniania.
**/
class Term : public QDate, private Initializable
{
    /** Zapisuje dany termin do danego strumienia.
      * @param stream Strumień do którego będzie zapisany termin.
      * @param term Termin który zostanie zapisany.
      * @throw char* Jeżeli zapisywany termin nie został zainicjalizowany
      * @return Ten sam strumień.
      **/
    friend QDataStream & operator<< (QDataStream& stream, const Term& term) throw(char*);

    /** Odczytuje dany termin z danego strumienia.
      * @param stream Strumień z którego będzie odczytany termin.
      * @param term Termin który zostanie zainicjalizowany odczytanymi danymi.
      * @throw char* Jeżeli Termin został wcześniej zainicjalizowany.
      * @return Ten sam strumień.
      **/
    friend QDataStream & operator>> (QDataStream& stream, Term& term) throw(char*);
public:
private:
    IDGenerator::ID                 eventID;        ///< Identyfikator wydarzenia
    IDGenerator::ID                 markID;         ///< Identyfikator oceny - skutku egzekucji wydarzenia
    bool                            revoke;         ///< Czy jest odwołany

public:
    /** Tworzy niezainicjalizowany obiekt reprezentujący termin jakiegoś wydarzenia.
      **/
    Term() : Initializable(false) {}

    /** Inicjalizuje obiekt reprezentujący termin danego wydarzenia.
      *
      * @param event Identyfikator wydarzenia związanego z tym terminem
      * @param date Data tego terminu.
      **/
    Term(IDGenerator::ID event,QDate date=QDate()) : QDate(date), eventID(event), Initializable(true), revoke(false) {}
    
    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const Term &o) const
    {
        return Initializable(*this)==Initializable(o) && QDate(*this)==QDate(o) && eventID==o.eventID && markID==o.markID && revoke==o.revoke;
    }
private:
};

/** Zapisuje dany termin do danego strumienia.
  * @param stream Strumień do którego będzie zapisany termin.
  * @param term Termin który zostanie zapisany.
  * @throw char* Jeżeli zapisywany termin nie został zainicjalizowany
  * @return Ten sam strumień.
  **/
QDataStream & operator<< (QDataStream& stream, const Term& term) throw(char*);

/** Odczytuje dany termin z danego strumienia.
  * @param stream Strumień z którego będzie odczytany termin.
  * @param term Termin który zostanie zainicjalizowany odczytanymi danymi.
  * @throw char* Jeżeli Termin został wcześniej zainicjalizowany.
  * @return Ten sam strumień.
  **/
QDataStream & operator>> (QDataStream& stream, Term& term) throw(char*);

#endif // TERM_H
