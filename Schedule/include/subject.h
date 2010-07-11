#ifndef SUBJECT_H
#define SUBJECT_H

#include <QtCore/QString>

#include "initializable.h"
#include "deletable.h"
#include "complist.h"
#include "generatoridgenerator.h"
#include "type.h"

/** Reprezentuje informacje o pojedyńczym przedmiocie. Wymaga aktywacji.
  * 
  * Składa się z:
  * - Pojemnika na oceny
  * - Skali ocen zarowno klasycznej jak i nowoczesnej
  * - Metod do prostej i szybkiej transformacji oceny (Mark) w ocene cząstkową.
  * - Generatora typów wydarzeń w ramach tego przedmiotu (IDGenerator).
  * - Pojemnika na typy możliwych wydarzeń w ramach tego przedmiotu (Type).
  * - Mapy ID <--> ComboID
  * - Współczynnika amortyzującego wagi poszczególnych typów wydarzeń.
  **/
class Subject : private Initializable, private Deletable
{
public:
private:
    QString                   name;               ///< Nazwa przedmiotu
    IDGenerator               typeIDGenerator;    ///< Generator identyfikatorów typów wydarzeń.
    CompList<Type>            types;              ///< Typy wydarzeń. Indeksowane types[TypeID] = wydarzenie TypeID
    CompList<IDGenerator::ID> typesMapping;       ///< Lista odnośników [pozycja w ComboBox]-->[pozycja w types]
public:
    /** Konstruktor. Inicjalizuje obiekt.
      * @param name Nazwa przedmiotu
      */
    Subject(QString name) : Initializable(true), Deletable(false), name(name), typeIDGenerator(GeneratorIDGenerator::nextIDGenerator()), types(CompList<Type>()), typesMapping(CompList<IDGenerator::ID>()) {}

    /** Konstruktor. Pozwala na tworzenie niezainicjalizowanych obiektów. */
    Subject() : Initializable(false), Deletable(false), name(QString()), typeIDGenerator(GeneratorIDGenerator::voidIDGenerator()), types(CompList<Type>()), typesMapping(CompList<IDGenerator::ID>()) {}

    /** Inicjalizuje dany obiekt.
      * @param name Nazwa przedmiotu
      * @throw QString Jeżeli dany obiekt już został zainicjalizowany
      */
    void initialize(QString name) throw(QString)
    {
        makeInitialized();
        this->name=name;
        typeIDGenerator=GeneratorIDGenerator::nextIDGenerator();
    }
    
    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const Subject &o) const;
    
private:
    };

#endif // SUBJECT_H
