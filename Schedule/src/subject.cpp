#include "../include/subject.h"

bool Subject::operator==(const Subject &o) const
{
    return Initializable(*this)==Initializable(o) && Deletable(*this)==Deletable(o) && name==o.name && typeIDGenerator==o.typeIDGenerator && types==o.types && typesMapping==o.typesMapping;
}
