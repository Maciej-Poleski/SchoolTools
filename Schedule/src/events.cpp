#include "../include/events.h"

bool Events::existOne=false;

QDataStream & operator<< (QDataStream& stream, const Events& events)
{
    return stream<<events.eventIDGenerator<<events.events;
}

QDataStream & operator>> (QDataStream& stream, Events& events)
{
    return stream>>events.eventIDGenerator>>events.events;
}

void Events::addEvent(Event newEvent)
{
    Events::events<<newEvent;
}

Events Events::create() throw(QString)
{
    if (existOne)
        throw "Obiekt już istnieje!";
    existOne=true;
    return Events();
}

bool Events::operator==(const Events& o) const
{
    return Initializable(*this)==Initializable(o) && eventIDGenerator==o.eventIDGenerator && events==o.events;
}
