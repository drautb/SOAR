#ifndef STATE_MACHINE_STACK
#define STATE_MACHINE_STACK

#include <stack>

#include "Log.h"

namespace SOAR
{
    namespace Util
    {
        namespace State
        {
            /**
             * This class represents a finite state machine implemented 
             * as a stack, rather than free form. For more flexibility,
             * use the pure StateMachine.
             */
            template <typename T>
            class StateMachineStack
            {
            private:

                /**
                 * The owner of this state state machine
                 */
                T*                              owner           = nullptr;

                /**
                 * The stack of states.
                 * A stack of pointers to IState<T>
                 */
                std::stack<IState<T>*>          stateStack;

                /**
                 * A pointer to a global state
                 */
                IState<T>*                      globalState     = nullptr;

            public:
                
                /**
                 * Constructor
                 */
                StateMachineStack(T* newOwner)
                {
                    owner = newOwner;
                    globalState = nullptr;
                    stateStack.clear();
                }

                /**
                 * Destructor
                 */
                ~StateMachineStack()
                {
                    if (globalState)
                        globalState->Exit();

                    stateStack.clear();
                }
                
                /**
                 * Used to initialize the global 
                 * state for this SM
                 * @param state pointer to an existing state
                 */
                void SetGlobalState(IState<T>* state)
                {
                    globalState = state;
                    globalState->Enter(owner);
                }

                /**
                 * Updates the SM by calling the execute method
                 * of the current valid states.
                 */
                void Update()
                {
                    if (globalState)
                        globalState.Execute(owner);

                    if (stateStack.top())
                        stateStack.top()->Execute(owner);
                }

                /**
                 * Pushes a new state onto the stack. Calls the
                 * enter method of the new state, but not the exit
                 * method of the old state.
                 * @param state Pointer to an existing state
                 */
                void PushState(IState<T>* state)
                {
                    if (!state)
                        SOAR_LOG_RECOVERABLE << "Attempted to push invalid state!";

                    stateStack.push(state);
                    stateStack.top()->Enter(owner);
                }

                /**
                 * Pops the current state off the stack, calling it's
                 * exit method, but not the Enter method of the state
                 * underneath.
                 */
                void PopState()
                {
                    stateStack.top()->Exit(owner);
                    stateStack.pop();
                }

            };
        }
    }
}

#endif

