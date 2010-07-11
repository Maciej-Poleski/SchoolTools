#ifndef EVENT_H
#define EVENT_H

#include <QtCore/QDataStream>
#include <QtCore/QString>

#include "initializable.h"
#include "complist.h"
#include "term.h"
#include "generatoridgenerator.h"

/** Reprezentuje zdarzenie w postaci zdefiniowanej przez użytkownika.
  * Posiada określony typ (zdefiniowany przez użytkownika z dostępnych możliwości (zdefiniowanych przez użytkownika)).
  * Powiązane z terminami.
  * 
  * Pozwala ustawić ocenę.
  * Składa się między innymi z:
  * - Identyfikatora (ID) tego wydarzenia.
  * - Identyfikatora (ID) typu tego wydarzenia.
  * - Identyfikatora (ID) przedmiotu (Subject) związanego z tym wydarzeniem.
  * - Pojemnika na terminy (Term) tego wydarzenia.
  * - Skali ocen i zasad oceniania.
  **/
class Event : private Initializable
{
    /** Zapisuje informacje o danym wydarzeniu do danego strumienia.
      * @param stream Strumień do którego będą zapisywane dane.
      * @param event Wydarzenie które będzie zapisywane.
      * @throw QString Jeżeli zapisywane wydarzenie nie zostało zainicjalizowane
      * @return Ten sam strumień.
      **/
    friend QDataStream & operator<< (QDataStream& stream, const Event& event) throw(QString);

    /** Odczytuje informacje o danym wydarzeniu z danego strumienia.
      * @param stream Strumień z którego będą odczytywane dane.
      * @param event Wydarzenie które zostanie zainicjalizowane wczytanymi danymi.
      * @throw QString Jeżeli Wydarzenie zostało wcześniej zainicjalizowane.
      * @return Ten sam strumień.
      **/
    friend QDataStream & operator>> (QDataStream& stream, Event& event) throw(QString);
public:
private:
    IDGenerator::ID subjectID;      ///< Identyfikator przedmiotu skojarzonego z wydarzeniem
    IDGenerator::ID typeID;         ///< Identyfikator typu wydarzenia
    IDGenerator::ID thisID;         ///< Identyfikator tego wydarzenia
    CompList<Term>  terms;          ///< Lista terminów danego wydarzenia
public:
    /** Inicjalizuje dane wydarzenie niezbędnymi informacjami.
      *
      * @param thisID Identyfikator tego wydarzenia
      * @param subjectID Identyfikator przedmiotu związanego z wydarzeniem
      * @param typeID Identyfikator typu wydarzenia
      * @param term Lista terminów tego wydarzenia. Może być pusta.
      **/
    Event(IDGenerator::ID thisID, IDGenerator::ID subjectID,IDGenerator::ID typeID,CompList<Term> term=CompList<Term>()) : thisID(thisID), subjectID(subjectID), typeID(typeID), Initializable(true), terms(term) {}

    /** Umożliwia tworzenie niezainicjalizowanych obiektów **/
    Event() : Initializable(false) {}

    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const Event &o) const;
private:
};

/** Zapisuje informacje o danym wydarzeniu do danego strumienia.
  * @param stream Strumień do którego będą zapisywane dane.
  * @param event Wydarzenie które będzie zapisywane.
  * @throw QString Jeżeli zapisywane wydarzenie nie zostało zainicjalizowane
  * @return Ten sam strumień.
  **/
QDataStream & operator<< (QDataStream& stream, const Event& event) throw(QString);

/** Odczytuje informacje o danym wydarzeniu z danego strumienia.
  * @param stream Strumień z którego będą odczytywane dane.
  * @param event Wydarzenie które zostanie zainicjalizowane wczytanymi danymi.
  * @throw QString Jeżeli Wydarzenie zostało wcześniej zainicjalizowane.
  * @return Ten sam strumień.
  **/
QDataStream & operator>> (QDataStream& stream, Event& event) throw(QString);

#endif // EVENT_H
