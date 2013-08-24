#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <map>

#include <GLFW/glfw3.h>

using namespace std;

namespace SOAR
{
    namespace Video
    {
        class WindowManager
        {
        private:

            /**
             * Core index of windows, maps window id's specified by
             * the user to GLFWwindow* pointers
             */
            map<int, GLFWwindow*>       windowIndex;

        private:

            /**
             * Private constructor for singleton 
             */
            WindowManager();

        public:

            /**
             * Destructor
             */
            ~WindowManager();
        
            /**
             * Singleton access method
             */
            static WindowManager& GetInstance();

            /**
             * This method creates a new GLFW window and adds it to the
             * window index if creation succeeded. 
             * @param  windowId   The user-supplied id used to identify the window
             * @param  width      The initial width of the window (pixels)
             * @param  height     The initial height of the window (pixels)
             * @param  title      The initial title of the window (optional)
             * @param  fullscreen Whether or not to make the window fullscreen
             * @return            True if window was successfully created and
             *                    added to the index, false otherwise.
             */
            bool CreateWindow(int windowId, int width, int height, 
                              const char* title="SOAR Window", bool fullscreen=false);

            /**
             * This method updates the windows that are being managed. It will 
             * swap the buffers and poll for new input on the active window.
             */
            void Update();

            /**
             * This method will activate the specified window. Only one window
             * may be active at any time.
             * @param windowId The id of the window to activate.
             */
            void MakeWindowActive(int windowId);

            /**
             * This method returns a handle to the specified window.
             * This allows the user to customize additional settings
             * for the window using GLFW calls
             * @param  windowId The id of the window for which a handle is desired
             * @return          A valid handle if windowId was valid, nullptr otherwise
             */
            GLFWwindow* Handle(int windowId);

        private:

            /**
             * This method is used to determine if the manager 
             * has a specified window id, and it is valid.
             * @param  id The id in question
             * @return    true if id is in the index and doesn't
             *            map to a nullptr
             */
            bool hasWindowId(int id);
        };
    }
}

#endif

