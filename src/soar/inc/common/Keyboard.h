#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <map>
#include <string>
#include <utility>

#include <GLFW/glfw3.h>

using namespace std;

#define KEY_STR(k)       SOAR::Keyboard::GetInstance().KeyToString(k)
#define KEY_STR_LONG(k)  SOAR::Keyboard::GetInstance().KeyToString(k, true)

void KeyboardCallback(GLFWwindow* window, int, int, int, int);

namespace SOAR 
{
    
    class Keyboard
    {
    public:
        /**
         * Class Constants
         */
        const static int KEY_COUNT      = 512;

        /**
         * Other Members
         */
        int keys[KEY_COUNT];

        bool keyLocks[KEY_COUNT];

        /**
         * String representations for each GLFW key
         */
        map<int, pair<string, string>> stringReps;

    private:
        /**
         * Constructor
         */
        Keyboard(void);

        // Not implemented
        Keyboard(Keyboard const &other);
        void operator=(Keyboard const &rhs);

    public:
        /**
         * Singleton Access
         */
        static Keyboard &GetInstance()
        {
            static Keyboard instance;

            return instance;
        }

        /** 
         * Destructor
         */
        ~Keyboard(void);

        /**
         * Determine if a key is currently being pressed down.
         * @param  key The integer representation of the key to query,
         *             as defined by GLFW_KEY_[key]
         * @return     True if the key is currently being pressed, false otherwise
         * @see        http://www.glfw.org/docs/3.0/group__keys.html
         */
        bool KeyIsDown(int key);

        /**
         * Determine if a key has been hit. If a key is being held down continously,
         * this method will only return true the first time it is called. Once the
         * key has been released, this method will register another hit if pressed again.
         * @param  key The integer representation of the key to query,
         *             as defined by GLFW_KEY_[key]
         * @return     True if the key was hit, false otherwise
         * @see        http://www.glfw.org/docs/3.0/group__keys.html
         */
        bool KeyIsHit(int key);

        /**
         * Retrieve a string representation of any key. When given a key,
         * this method will return a string representation of that key.
         * By default, it returns a short description, no longer than a 
         * few characters. If [@param verbose] is true, it will return
         * a full string representation.
         * @param  key     The integer representation of the key to query,
         *                 as defined by GLFW_KEY_[key]
         * @param  verbose Whether or not to return a long string representation
         * @return         A string representation of key.
         * @see        http://www.glfw.org/docs/3.0/group__keys.html
         */
        string KeyToString(int key, bool verbose=false);

    private:

        /**
         * This method clears the existing stringReps map, and 
         * re-initializes it with all the appropriate key-value pairs.
         */
        void populateStringReps();
    };

}

#endif


