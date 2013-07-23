#include <GLFW/glfw3.h>

#include "Mouse.h"

using namespace SOAR;
using namespace Input;

void MousePosCallback(GLFWwindow* window, double newXPos, double newYPos)
{
    Mouse::GetInstance().xPos = (int)newXPos;
    Mouse::GetInstance().yPos = (int)newYPos;
}

void MouseButtonCallback(GLFWwindow* window, int button, int pressed, int idk)
{
    Mouse::GetInstance().buttons[button] = pressed;
    Mouse::GetInstance().buttonLocks[button] = pressed > 0 ? true : false;
}

Mouse::Mouse(void)
{

}

Mouse::~Mouse()
{

}

bool Mouse::ButtonIsDown(int button)
{
    return buttons[button];
}

bool Mouse::ButtonIsHit(int button)
{
    bool hit = buttons[button] && buttonLocks[button];

    buttonLocks[button] = false;

    return hit;
}