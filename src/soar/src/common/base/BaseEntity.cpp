#include <base/BaseEntity.h>
#include <util/Log.h>

using namespace SOAR;
using namespace Base;

int BaseEntity::nextValidId = 0;

BaseEntity::BaseEntity(int id)
{
    setId(id);
}

BaseEntity::~BaseEntity()
{

}

int BaseEntity::Id()const
{
    return id;
}

void BaseEntity::setId(int id)
{
    if (id < nextValidId)
    {
        SOAR_LOG_RECOVERABLE << "Attempted to give invalid id " << id << " to BaseEntity. nextValidId: " << nextValidId;
        this->id = nextValidId++;
    }
    else
    {
        this->id = id;
        nextValidId = id + 1;
    }
}
