#include "../include/idgenerator.h"
#include "generatoridgenerator.h"

void IDGenerator::initialize() throw(char*)
{
    if (type!=0LL)
        throw "Error";
    *this=GeneratorIDGenerator::nextIDGenerator();
}

IDGenerator& IDGenerator::operator=(const IDGenerator& o) throw(char*)
{
    if (type!=0LL)
        throw "Error";
    type=o.type;
    freeID=o.freeID;
    return *this;
}

QDataStream & operator<< (QDataStream& stream, const IDGenerator::ID& id)
{
    return stream<<id.type<<id.id;
}

QDataStream & operator>> (QDataStream& stream, IDGenerator::ID& id)
{
    return stream>>id.type>>id.id;
}

QDataStream & operator<< (QDataStream& stream, const IDGenerator& generator)
{
    return stream<<generator.type<<generator.freeID;
}

QDataStream & operator>> (QDataStream& stream, IDGenerator& generator)
{
    return stream>>generator.type>>generator.freeID;
}

IDGenerator::ID& IDGenerator::ID::operator=(const ID& o) throw(char*)
{
    if (type!=0LL || (type==o.type && o.id==0))
        throw "Nie wolno nadpisywać identyfikatorów!";
    id=o.id;
    type=o.type;
    return *this;
}
