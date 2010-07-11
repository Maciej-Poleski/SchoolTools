#include "../include/event.h"

QDataStream & operator<< (QDataStream& stream, const Event& event) throw(QString)
{
    event.checkInitialized();
    stream<<event.thisID<<event.subjectID<<event.typeID;
    try
    {
        return stream<<event.terms;
    } catch(const char * const e)
    {
        throw QString("Wystąpił wyjątek podczas odczytu listy terminów wydarzenia:\n")+e;
    }
}

QDataStream & operator>> (QDataStream& stream, Event& event) throw(QString)
{
    event.makeInitialized();
    return stream>>event.thisID>>event.subjectID>>event.typeID>>event.terms;
}

bool Event::operator==(const Event &o) const
{
    return Initializable(*this)==Initializable(o) && subjectID==o.subjectID && typeID==o.typeID && thisID==o.thisID && terms==o.terms;
}
