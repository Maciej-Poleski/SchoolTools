#include "../include/abstractidgenerator.h"

ID AbstractIDGenerator::createID()
{
    return ID(ID++);
}

ID AbstractIDGenerator::createVoidID()
{
    return ID(0);
}
