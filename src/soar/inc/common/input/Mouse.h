#ifndef MOUSE_H
#define MOUSE_H

#include <GLFW/glfw3.h>

#define MOUSE SOAR::Input::Mouse::GetInstance()

void MousePosCallback(GLFWwindow* window, double newXPos, double newYPos);
void MouseButtonCallback(GLFWwindow* window, int button, int pressed, int);

namespace SOAR
{
    namespace Input
    {
        class Mouse
        {
        public:

            const static int        BUTTON_COUNT = 3;

            enum 
            {
                LM_BUTTON=0,
                MM_BUTTON,
                RM_BUTTON
            };

            int                     xPos, yPos;
            
            int                     buttons[BUTTON_COUNT];
            
            bool                    buttonLocks[BUTTON_COUNT];

        private:
            Mouse(void);

            // Not implemented
            Mouse(Mouse const &other);
            void operator=(Mouse const &rhs);

        public:

            /**
             * Singleton Access
             */
            static Mouse &GetInstance()
            {
                static Mouse instance;

                return instance;
            }

            /** 
             * Destructor
             */
            ~Mouse(void);

            bool ButtonIsDown(int button)const;

            bool LMBIsDown()const{return ButtonIsDown(LM_BUTTON);}
            bool MMBIsDown()const{return ButtonIsDown(MM_BUTTON);}
            bool RMBIsDown()const{return ButtonIsDown(RM_BUTTON);}

            bool ButtonIsHit(int button);
        };
    }
}

#endif