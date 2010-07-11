#ifndef GENERATORIDGENERATOR_H
#define GENERATORIDGENERATOR_H

#include "idgenerator.h"

/** Ta klasa odpowiada za generowanie generatorów identyfikatorów **/
class GeneratorIDGenerator
{
public:
private:
    static quint64 freeIDGenerator;            ///< Pierwszy dostępny typ Generatora identyfikatorów
public:
    /** Generuje następny generator identyfikatorów **/
    static IDGenerator nextIDGenerator();
    
    /** Generuje niezainicjalizowany (błędny) generator identyfikatorów **/
    static IDGenerator voidIDGenerator();
private:
    /** Nie pozwalam na tworzenie obiektów tej klasy **/
    GeneratorIDGenerator() {}
};

#endif // GENERATORIDGENERATOR_H
