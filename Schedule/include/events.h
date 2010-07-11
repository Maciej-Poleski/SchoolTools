#ifndef EVENTS_H
#define EVENTS_H

#include <QtCore/QFile>

#include "initializable.h"
#include "complist.h"
#include "event.h"
#include "generatoridgenerator.h"

/** Klasa przechowuje wszystkie wydarzenia i zarządza nimi. **/
class Events : private Initializable
{
    /** Zapisuje informacje o wydarzeniach do danego strumienia.
      * @param stream Strumień do którego będą zapisywane dane.
      * @param events Wydarzenia które będzie zapisywane.
      * @return Ten sam strumień.
      **/
    friend QDataStream & operator<< (QDataStream& stream, const Events& events);

    /** Odczytuje informacje o wydarzeniach z danego strumienia.
      * @param stream Strumień z którego będą odczytywane dane.
      * @param events Obiekt klasy Events który zostanie zainicjalizowany wczytanymi danymi.
      * @return Ten sam strumień.
      **/
    friend QDataStream & operator>> (QDataStream& stream, Events& events);

public:
    IDGenerator      eventIDGenerator;              ///< Generator identyfikatorów wydarzeń.
private:
    CompList<Event>  events;                        ///< Lista wszystkich wydarzeń. Będzie się powiększać.

    static bool existOne;       ///< Czy istnieje jakiś obiekt tej klasy

public:

    /** Tworzy instancje klasy.
      * @throw QString Jeżeli już wywołano tę metodę
      * @return Nowy obiekt tej klasy
      **/
    static Events create() throw(QString);

    /** Dodaje nowe wydarzenie.
      * @param newEvent   Wydarzenie które ma zostać dodane do bazy danych.
      **/
    void addEvent(Event newEvent);

    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const Events &o) const;
    
private:
    /** Oznacza nowy obiekt jako niezainicjalizowany. **/
    Events() : Initializable(false),eventIDGenerator(GeneratorIDGenerator::nextIDGenerator()) {}

};

/** Zapisuje informacje o wydarzeniach do danego strumienia.
  * @param stream Strumień do którego będą zapisywane dane.
  * @param events Wydarzenia które będzie zapisywane.
  * @return Ten sam strumień.
  **/
QDataStream & operator<< (QDataStream& stream, const Events& events);

/** Odczytuje informacje o wydarzeniach z danego strumienia.
  * @param stream Strumień z którego będą odczytywane dane.
  * @param events Obiekt klasy Events który zostanie zainicjalizowany wczytanymi danymi.
  * @return Ten sam strumień.
  **/
QDataStream & operator>> (QDataStream& stream, Events& events);

#endif // EVENTS_H
