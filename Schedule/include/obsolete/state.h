#ifndef STATE_H
#define STATE_H

#include <QtCore/QStringList>
#include <QtCore/QList>
#include "generatoridgenerator.h"

namespace obsolete
{

/** Klasa przechowująca wszelkie informacje o stanie aplikacji, bazy danych i danych. Jest to kontener na informacje o przedmiotach.

    Nie wolno tworzyć obiektów tej klasy, wszystkie pola są statyczne.
    **/
class State
{
public:
    static IDGenerator                      subjectIDGenerator; ///< Generator identyfikatorów przedmiotów
    static QStringList                      subjects;           ///< Lista przedmiotów. subjects[SubjectID] = Przedmiot o zadanym identyfikatorze.
    static QList<IDGenerator::ID>           subjectMapping;     ///< Lista odnośników [pozycja w ComboBox]-->[pozycja w subjects]

private:
    State() {}                                       ///< Nie wolno tworzyć obiektów tej klasy.
};

}

#endif // STATE_H
