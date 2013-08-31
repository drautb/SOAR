#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include <base/Telegram.h>

namespace SOAR
{
    namespace Base
    {
        class BaseEntity
        {
        private: 

            /**
             * This entity's ID
             */
            int             id;

            /**
             * The next id to be used for an object
             */
            static int      nextValidId;

        public:

            /**
             * Constructor
             */
            BaseEntity(int id=nextValidId);

            /**
             * Destructor
             */
            virtual ~BaseEntity();

            /**
             * All entities must implemente an update function
             */
            virtual void Update()=0;

            /**
             * All entities must provide a method for hanlding messages
             * @param  msg The message sent to this entity
             * @return     True if the message was handled, false if not
             */
            virtual bool HandleMessage(const Telegram& msg)=0;

            /**
             * Accessor for this entity's id
             * @return The id of this entity
             */
            int Id()const;

        private:

            /**
             * This method takes care of assigning this entity it's id.
             * It will make sure that if the user supplies an id, it 
             * hasn't already been used.
             * @param id The id to use for this object
             */
            void setId(int id);

        };

        inline bool operator==(const BaseEntity& lhs, const BaseEntity& rhs)
        {
            return lhs.Id() == rhs.Id();
        }
    }
}

#endif
