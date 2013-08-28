#include <map>

#include <GLFW/glfw3.h>

#include <util/Log.h>
#include <video/WindowManager.h>
#include <input/Keyboard.h>
#include <input/Mouse.h>

using namespace std;
using namespace SOAR;
using namespace Video;

WindowManager::WindowManager()
{
    if (!glfwInit())
        SOAR_LOG_FATAL << "GLFW Failed to initialize!";

    windowIndex.clear();
}

WindowManager::~WindowManager()
{
    windowIndex.clear();

    glfwTerminate();
}

WindowManager& WindowManager::GetInstance()
{
    static WindowManager instance;

    return instance;
}

bool WindowManager::CreateWindow(int windowId, int width, int height,
                                 const char* title, bool fullscreen)
{
    if (hasWindowId(windowId))
    {
        SOAR_LOG_RECOVERABLE << "Failed to create window, window id: " << windowId << " is already in use";
        return false;
    }

    GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;

    GLFWwindow* window = glfwCreateWindow(width, height, title, monitor, nullptr);

    if (!window)
    {
        SOAR_LOG_FATAL << "glfwCreateWindow Failed, title: " << title;
        return false;
    }

    // Register the input functions
    glfwSetKeyCallback(window, KeyboardCallback);
    glfwSetCursorPosCallback(window, MousePosCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);

    windowIndex[windowId] = window;

    return true;
}

void WindowManager::Update()
{
    glfwSwapBuffers(glfwGetCurrentContext());

    glfwPollEvents();
}

void WindowManager::MakeWindowActive(int windowId)
{
    if (hasWindowId(windowId))
        glfwMakeContextCurrent(windowIndex[windowId]);
}

GLFWwindow* WindowManager::Handle(int windowId)
{
    if (!hasWindowId(windowId))
        return nullptr;

    return windowIndex[windowId];
}

bool WindowManager::hasWindowId(int id)
{
    if (windowIndex.find(id) != windowIndex.end())
        return windowIndex[id] != nullptr;

    return false;
}
