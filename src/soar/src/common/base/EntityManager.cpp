#include <map>

#include <base/BaseEntity.h>
#include <base/EntityManager.h>

using namespace std;
using namespace SOAR;
using namespace Base;

EntityManager::EntityManager()
{
    entityIndex.clear();
}

EntityManager::~EntityManager()
{
    entityIndex.clear();
}

EntityManager& EntityManager::GetInstance()
{
    static EntityManager instance;

    return instance;
}

void EntityManager::RegisterEntity(BaseEntity* entity)
{
    entityIndex[entity->Id()] = entity;
}

void EntityManager::UnRegisterEntity(BaseEntity* entity)
{
    entityIndex.erase(entity->Id());
}

BaseEntity* EntityManager::GetById(int id)
{
    return entityIndex[id];
}
