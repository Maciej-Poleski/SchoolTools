#include "../include/generatoridgenerator.h"

quint64 GeneratorIDGenerator::freeIDGenerator=1;

IDGenerator GeneratorIDGenerator::nextIDGenerator()
{
    return IDGenerator(freeIDGenerator++);
}

IDGenerator GeneratorIDGenerator::voidIDGenerator()
{
    return IDGenerator(0LL);
}
