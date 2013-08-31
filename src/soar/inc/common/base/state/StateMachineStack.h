#ifndef STATE_MACHINE_STACK
#define STATE_MACHINE_STACK

#include <stack>

#include <base/state/IStackableState.h>
#include <util/Log.h>

namespace SOAR
{
    namespace Base
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
                 * A stack of pointers to IStackableState<T>
                 */
                std::stack<IStackableState<T>*>          stateStack;

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
                    clear();
                }

                /**
                 * Destructor
                 */
                ~StateMachineStack()
                {
                    if (globalState)
                        globalState->Exit(owner);

                    clear();
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
                    if (globalState != nullptr)
                        globalState->Execute(owner);

                    if (!stateStack.empty() && stateStack.top() != nullptr)
                        stateStack.top()->Execute(owner);
                }

                /**
                 * This method passes messages on to the individual states
                 * @param msg The message that was received
                 */
                bool HandleMessage(const Telegram& msg)
                {
                    if (!stateStack.empty() && stateStack.top() != nullptr && 
                        stateStack.top()->OnMessage(owner, msg))
                        return true;

                    if (globalState != nullptr && globalState->OnMessage(owner, msg))
                        return true;

                    return false;
                }

                /**
                 * Invokes the render method of the current states
                 */
                void Render()
                {
                    if (globalState != nullptr)
                        globalState->Render(owner);

                    if (!stateStack.empty() && stateStack.top() != nullptr)
                        stateStack.top()->Render(owner);
                }

                /**
                 * Pushes a new state onto the stack. Calls the
                 * enter method of the new state, and the pause method of the old state
                 * @param state Pointer to an existing state
                 */
                void PushState(IStackableState<T>* state)
                {
                    if (!state)
                        SOAR_LOG_RECOVERABLE << "Attempted to push invalid state!";

                    if (stateStack.top() != nullptr)
                        stateStack.top()->Pause(owner);

                    stateStack.push(state);
                    stateStack.top()->Enter(owner);
                }

                /**
                 * Pops the current state off the stack, calling it's
                 * exit method, and the Resume method of the state underneath.
                 */
                void PopState()
                {
                    stateStack.top()->Exit(owner);
                    stateStack.pop();

                    if (stateStack.top() != nullptr)
                        stateStack.top()->Resume(owner);
                }

            private:

                /**
                 * Clears everything out of the stateStack
                 */
                void clear()
                {
                    while (!stateStack.empty())
                        PopState();
                }

            };
        }
    }
}

#endif

