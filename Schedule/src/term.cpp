#include "../include/term.h"

QDataStream & operator<< (QDataStream& stream, const Term& term) throw(char*)
{
    term.checkInitialized();
    #ifdef QDATE_WORKAROUND
    QDate tmp(term);
    int a,b,c;
    tmp.getDate(&a,&b,&c);
    stream<<a<<b<<c;
    #else
    stream<<QDate(term);
    #endif
    return stream<<term.eventID<<term.markID<<term.revoke;
}

QDataStream & operator>> (QDataStream& stream, Term& term) throw(char*)
{
    term.makeInitialized();
    #ifdef QDATE_WORKAROUND
    int a,b,c;
    stream>>a>>b>>c;
    term.setDate(a,b,c);
    #else
    operator>>(stream,static_cast<QDate&>(term));
    #endif
    return stream>>term.eventID>>term.markID>>term.revoke;
}
