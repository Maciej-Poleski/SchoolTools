#ifndef SUBJECTS_H
#define SUBJECTS_H

#include "initializable.h"
#include "idgenerator.h"
#include "subject.h"
#include "generatoridgenerator.h"
#include "complist.h"

/** Obiekt klasy reprezentuje wszystkie przedmioty.
  * 
  * Składa się z:
  * - Przedmiotów (Subject)
  * - Generatora identyfikatorów przedmiotów
  * - Mapy ID <--> ComboID
  * - Globalnych (statutowych) zasad oceniania i skali ocen zarówno nowoczesnych jak i klasycznych (NALEŻY JE ROZUMIEĆ PRZYROSTOWO!).
  **/
class Subjects : private Initializable
{
public:
    IDGenerator                 subjectIDGenerator; ///< Generator identyfikatorów przedmiotów
    CompList<Subject>           subjects;           ///< Lista przedmiotów
    CompList<IDGenerator::ID>   subjectMapping;     ///< Lista odnośników [pozycja w ComboBox]-->[pozycja w subjects]

private:
    static bool existOne;       ///< Czy istnieje jakiś obiekt tej klasy

public:
    /** Tworzy instancje klasy.
      * @throw char* Jeżeli już wywołano tę metodę
      * @return Nowy obiekt tej klasy
      **/
    static Subjects create() throw(char*);
    
    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const Subjects &o) const;

private:
    /** Oznacza nowy obiekt jako niezainicjalizowany. **/
    Subjects() : Initializable(false),subjectIDGenerator(GeneratorIDGenerator::voidIDGenerator()) {}
};

#endif // SUBJECTS_H
