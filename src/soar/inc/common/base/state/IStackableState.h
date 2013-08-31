#ifndef I_STACKABLE_STATE
#define I_STACKABLE_STATE

#include <base/state/IState.h>

using namespace SOAR;
using namespace Base;
using namespace State;

namespace SOAR
{
    namespace Base
    {
        namespace State
        {
            /**
             * This class is an interface that all states used 
             * by the StateStack must implement. Enter and Exit are 
             * only called when a state enters or leaves the stack,
             * so this interface adds methods that are called when a state
             * either is pushed down or popped up to the top of the stack.
             */
            template <typename T>
            class IStackableState : public IState<T>
            {
            public:
                
                /**
                 * Virtual Destructor
                 */
                virtual ~IStackableState();

                /**
                 * This method is called when a state that is 
                 * currently on the top of the stack, gets pushed
                 * down.                
                 */
                virtual void Pause(T*)=0;

                /**
                 * This method is called when a state that is already in
                 * the stack becomes the active (Top) state again. 
                 */
                virtual void Resume(T*)=0;
            
            };
        }
    }
}

#endif
