#include "../include/mark.h"

QDataStream & operator<< (QDataStream& stream, const Mark& mark) throw(QString)
{
    mark.checkInitialized();
    return stream<<mark.top<<mark.sign<<mark.termID;
}

QDataStream & operator>> (QDataStream& stream, Mark& mark) throw(QString)
{
    mark.makeInitialized();
    return stream>>mark.top>>mark.sign>>mark.termID;
}
