#ifndef MESSAGE_DISPATCHER_H
#define MESSAGE_DISPATCHER_H

#include <set>

#include <base/BaseEntity.h>
#include <base/Telegram.h>

using namespace std;
using namespace SOAR;
using namespace Base;

#define MD SOAR::Base::MessageDispatcher::GetInstance()

namespace SOAR
{
    namespace Base
    {
        class MessageDispatcher
        {
        private:

            /**
             * This is the message queue for delayed messages.
             * We use a std::set instead of a std::priority_queue beacuse
             * it will automatically discard duplicate messages
             */
            set<Telegram>        msgQueue;

        private:

            /**
             * Private constructor for singleton
             */
            MessageDispatcher();

        public:

            /**
             * Destructor
             */
            ~MessageDispatcher();
        
            /**
             * Singleton Access Method
             */
            static MessageDispatcher& GetInstance();

            /**
             * This method is used by the world to send messages!
             * It automatically takes care of dispatching messages immediately,
             * or saving them to be dispatched later
             * @param senderId   The id of the sending entity
             * @param receiverId The id of the receiving entity
             * @param msg        The message itself
             * @param delay      The amount of time to wait before sending it
             * @param extraInfo  A pointer to any extra info to send
             */
            void DispatchMsg(int senderId, int receiverId, int msg, 
                             double delay=0.0, void* extraInfo=nullptr);

            /**
             * This method takes care of dispatching messages that had a delay 
             * value. It must be called often in order for messages to be 
             * delivered! (Each cycle)
             */
            void DispatchDelayedMessages();

        private:

            /**
             * This method actually sends the message to an entity.
             * @param receiver The entity to receive the message
             * @param msg      The message to send
             */
            void discharge(BaseEntity* receiver, const Telegram& msg);

        };
    }
}

#endif
