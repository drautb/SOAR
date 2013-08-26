#ifndef I_STATE_H
#define I_STATE_H

namespace SOAR
{
    namespace Util
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

            };
        }
    }
}

#endif

