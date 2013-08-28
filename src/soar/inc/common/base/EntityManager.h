#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <map>

#include <base/BaseEntity.h>

using namespace std;
using namespace SOAR;
using namespace Base;

#define EM SOAR::Base::EntityManager::GetInstance()

namespace SOAR
{
    namespace Base
    {
        class EntityManager
        {
        private:

            /**
             * entity index, maps entity id's to entities
             */
            map<int, BaseEntity*>       entityIndex;

        private:

            /**
             * Private constructor for singleton
             */
            EntityManager();

        public:

            /**
             * Destructor
             */
            ~EntityManager();
        
            /**
             * Singleton Access Method
             */
            static EntityManager& GetInstance();

            /**
             * This method registers a new entity in the index
             * @param entity The entity to register
             */
            void RegisterEntity(BaseEntity* entity);

            /**
             * This method will remove the given entity from the entityIndex 
             * @param entity The entity to remove
             */
            void UnRegisterEntity(BaseEntity* entity);

            /**
             * This method grabs an entity from the manager by it's id
             * @param  id The id of the entity to get
             * @return    A pointer to the entity
             */
            BaseEntity* GetById(int id);

        };
    }
}

#endif
