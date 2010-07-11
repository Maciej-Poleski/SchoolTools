#include "../include/abstractid.h"

QDataStream & operator<< (QDataStream& stream, const AbstractID& ID)
{
    return stream<<ID.ID;
}

QDataStream & operator>> (QDataStream& stream, AbstractID& ID)
{
    return stream>>ID.ID;
}
