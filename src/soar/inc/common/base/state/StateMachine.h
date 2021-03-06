#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <base/state/IState.h>
#include <util/Log.h>

namespace SOAR
{
    namespace Base
    {
        namespace State
        {
            template <typename T>
            class StateMachine
            {
            private:

                /**
                 * Pointer to the owner of this FSM
                 */
                T*              owner               = nullptr;

                /**
                 * The current state of this FSM
                 */
                IState<T>*      currentState        = nullptr;

                /**
                 * The previous state of this FSM
                 */
                IState<T>*      previousState       = nullptr;

                /**
                 * The global state, this state's logic is invoked 
                 * no matter what the current state of the FSM is.
                 */
                IState<T>*      globalState         = nullptr;

            public:
                
                /**
                 * Constructor
                 */
                StateMachine(T* newOwner)
                {
                    owner = newOwner;
                    currentState = previousState = globalState = nullptr;
                }

                /**
                 * Sets the currenct state of the FSM,
                 * use to initialize the FSM
                 * @param state A pointer to an existing State
                 */
                void SetCurrentState(IState<T>* state)
                {
                    currentState = state;
                }

                /**
                 * Sets the previous state of the FSM,
                 * use to initilaize the FSM.
                 * @param state A pointer to an existing state
                 */
                void SetPreviousState(IState<T>* state)
                {
                    currentState = state;
                }

                /**
                 * Sets the global state of the FSM,
                 * use to initialize the FSM.
                 * @param state A pointer to an exisiting state
                 */
                void SetGlobalState(IState<T>* state)
                {
                    globalState = state;
                }

                /**
                 * This method updates the FSM, calling
                 * the execute methods of the valid states.
                 */
                void Update()const
                {
                    if (globalState != nullptr)
                        globalState->Execute(owner);

                    if (currentState != nullptr)
                        currentState->Execute(owner);
                }

                /**
                 * This method passes messages on to the individual states
                 * @param msg The message that was received
                 */
                bool HandleMessage(const Telegram& msg)
                {
                    if (currentState != nullptr && currentState->OnMessage(owner, msg))
                        return true;

                    if (globalState != nullptr && globalState->OnMessage(owner, msg))
                        return true;

                    return false;
                }

                /**
                 * Invokes the Render method of all the current states
                 */
                void Render()const
                {
                    if (globalState != nullptr)
                        globalState->Render(owner);

                    if (currentState != nullptr)
                        currentState->Render(owner);
                }

                /**
                 * This method is used to change the state of the FSM.
                 * It updates the record of the previous state, and calls 
                 * the Enter/Exit functions appropriately.
                 * @param newState [description]
                 */
                void ChangeState(IState<T>* newState)
                {
                    if (!newState || newState == nullptr)
                        SOAR_LOG_RECOVERABLE << "Attempted to change to a null state";

                    previousState = currentState;
                    currentState->Exit(owner);

                    currentState = newState;
                    currentState->Enter(owner);
                }

                /**
                 * Used to go back to the previous state.
                 */
                void RevertToPreviousState()
                {
                    ChangeState(previousState);
                }
            };   
        }
    }
}

#endif
