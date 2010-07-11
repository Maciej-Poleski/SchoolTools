#ifndef ID_H
#define ID_H

#include "eventid.h"
#include "markid.h"
#include "typeid.h"
#include "subjectid.h"

namespace obsolete
{

/** Korzeń nowej idei uniwersalnego ID **/
class ID : public EventID, public MarkID, public TypeID, public SubjectID
{
};

}

#endif // ID_H
