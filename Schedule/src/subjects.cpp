#include "../include/subjects.h"

bool Subjects::existOne=false;

Subjects Subjects::create() throw(char*)
{
    if (existOne)
        throw "Obiekt już istnieje!";
    existOne=true;
    return Subjects();
}

bool Subjects::operator==(const Subjects &o) const
{
    return Initializable(*this)==Initializable(o) && subjectIDGenerator==o.subjectIDGenerator && subjects==o.subjects && subjectMapping==o.subjectMapping;
}
