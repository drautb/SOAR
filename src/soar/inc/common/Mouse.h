#ifndef MOUSE_H
#define MOUSE_H

#include <GLFW/glfw3.h>

void MousePosCallback(GLFWwindow* window, double newXPos, double newYPos);
void MouseButtonCallback(GLFWwindow* window, int button, int pressed, int);

namespace SOAR
{

    class Mouse
    {
    public:

        const static int        BUTTON_COUNT = 3;

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

        bool ButtonIsDown(int button);

        bool ButtonIsHit(int button);
    };

}

#endif