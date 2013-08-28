#ifndef I_STATE_H
#define I_STATE_H

#include <base/Telegram.h>

namespace SOAR
{
    namespace Base
    {
        namespace State
        {
            /**
             * This class is an interface that all States used by 
             * the various State Machines must implement.
             */
            template <typename T>
            class IState
            {
            public:
            
                /**
                 * Virtual Destructor
                 */
                virtual ~IState(){}

                /**
                 * Called when a state machine enters this state.
                 */
                virtual void Enter(T*)=0;

                /**
                 * Called each update cycle of a SM for the current state
                 */
                virtual void Execute(T*)=0;

                /**
                 * Called when a state is exited.
                 */
                virtual void Exit(T*)=0;
                
                /**
                 * Called if the owner of the state machine passes messages in.
                 */
                virtual bool OnMessage(T*, const Telegram&)=0;

                /**
                 * Called during the rendering loop
                 */
                virtual void Render(T*)=0;

            };
        }
    }
}

#endif

