#include <iostream>

#include <GLFW/glfw3.h>

#include "Keyboard.h"

using namespace std;

using namespace SOAR;

void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Keyboard::GetInstance().keys[key] = action == GLFW_PRESS || action == GLFW_REPEAT;
    Keyboard::GetInstance().keyLocks[key] = (action == GLFW_PRESS || action == GLFW_REPEAT) ? true : false;
}

Keyboard::Keyboard(void)
{
    for (int k=0; k<KEY_COUNT; k++)
        keyLocks[k] = false;

    populateStringReps();
}

/** 
 * Destructor
 */

Keyboard::~Keyboard(void)
{

}

/**
 * Other Methods
 */
bool Keyboard::KeyIsDown(int key)
{
    return keys[key] == GLFW_PRESS;
}

bool Keyboard::KeyIsHit(int key)
{
    bool hit = keys[key] && keyLocks[key];
    keyLocks[key] = false;
    return hit;
}

string Keyboard::KeyToString(int key, bool verbose)
{
    if (!stringReps.count(key))
        key = GLFW_KEY_UNKNOWN;

    return verbose ? stringReps[key].second : stringReps[key].first;
}

void Keyboard::populateStringReps()
{
    stringReps.clear();

    /**
     *    KEY DEFNITION (INT)          SHORT TEXT                VERBOSE TEXT       
     */
    stringReps = {
        { GLFW_KEY_UNKNOWN,         { "Key Not Recognized",     "Key Not Recognized" } },
        { GLFW_KEY_SPACE,           { "Space",                  "Spacebar" } },
        { GLFW_KEY_APOSTROPHE,      { "'",                      "Apostrophe" } },
        { GLFW_KEY_COMMA,           { ",",                      "Comma" } },
        { GLFW_KEY_MINUS,           { "-",                      "Minus" } },
        { GLFW_KEY_PERIOD,          { ".",                      "Period" } },
        { GLFW_KEY_SLASH,           { "/",                      "Forward Slash" } },
        { GLFW_KEY_0,               { "0",                      "0" } },
        { GLFW_KEY_1,               { "1",                      "1" } },
        { GLFW_KEY_2,               { "2",                      "2" } },
        { GLFW_KEY_3,               { "3",                      "3" } },
        { GLFW_KEY_4,               { "4",                      "4" } },
        { GLFW_KEY_5,               { "5",                      "5" } },
        { GLFW_KEY_6,               { "6",                      "6" } },
        { GLFW_KEY_7,               { "7",                      "7" } },
        { GLFW_KEY_8,               { "8",                      "8" } },
        { GLFW_KEY_9,               { "9",                      "9" } },
        { GLFW_KEY_SEMICOLON,       { ";",                      "Semicolon" } },
        { GLFW_KEY_EQUAL,           { "=",                      "Equal" } },
        { GLFW_KEY_A,               { "A",                      "A" } },
        { GLFW_KEY_B,               { "B",                      "B" } },
        { GLFW_KEY_C,               { "C",                      "C" } },
        { GLFW_KEY_D,               { "D",                      "D" } },
        { GLFW_KEY_E,               { "E",                      "E" } },
        { GLFW_KEY_F,               { "F",                      "F" } },
        { GLFW_KEY_G,               { "G",                      "G" } },
        { GLFW_KEY_H,               { "H",                      "H" } },
        { GLFW_KEY_I,               { "I",                      "I" } },
        { GLFW_KEY_J,               { "J",                      "J" } },
        { GLFW_KEY_K,               { "K",                      "K" } },
        { GLFW_KEY_L,               { "L",                      "L" } },
        { GLFW_KEY_M,               { "M",                      "M" } },
        { GLFW_KEY_N,               { "N",                      "N" } },
        { GLFW_KEY_O,               { "O",                      "O" } },
        { GLFW_KEY_P,               { "P",                      "P" } },
        { GLFW_KEY_Q,               { "Q",                      "Q" } },
        { GLFW_KEY_R,               { "R",                      "R" } },
        { GLFW_KEY_S,               { "S",                      "S" } },
        { GLFW_KEY_T,               { "T",                      "T" } },
        { GLFW_KEY_U,               { "U",                      "U" } },
        { GLFW_KEY_V,               { "V",                      "V" } },
        { GLFW_KEY_W,               { "W",                      "W" } },
        { GLFW_KEY_X,               { "X",                      "X" } },
        { GLFW_KEY_Y,               { "Y",                      "Y" } },
        { GLFW_KEY_Z,               { "Z",                      "Z" } },
        { GLFW_KEY_LEFT_BRACKET,    { "[",                      "Left Bracket" } },
        { GLFW_KEY_BACKSLASH,       { "\\",                     "Backslash" } },
        { GLFW_KEY_RIGHT_BRACKET,   { "]",                      "Right Bracket" } },
        { GLFW_KEY_GRAVE_ACCENT,    { "`",                      "Backtick" } },
        { GLFW_KEY_WORLD_1,         { "Non-US #1",              "Non-US #1" } },
        { GLFW_KEY_WORLD_2,         { "Non-US #2",              "Non-US #2" } },
        { GLFW_KEY_ESCAPE,          { "Esc",                    "Escape" } },
        { GLFW_KEY_ENTER,           { "Enter",                  "Enter" } },
        { GLFW_KEY_TAB,             { "Tab",                    "Tab" } },
        { GLFW_KEY_BACKSPACE,       { "Bkspc",                  "Backspace" } },
        { GLFW_KEY_INSERT,          { "Ins",                    "Insert" } },
        { GLFW_KEY_DELETE,          { "Del",                    "Delete" } },
        { GLFW_KEY_RIGHT,           { "Right",                  "Right Arrow" } },
        { GLFW_KEY_LEFT,            { "Left",                   "Left Arrow" } },
        { GLFW_KEY_DOWN,            { "Down",                   "Down Arrow" } },
        { GLFW_KEY_UP,              { "Up",                     "Up Arrow" } },
        { GLFW_KEY_PAGE_UP,         { "PgUp",                   "Page Up" } },
        { GLFW_KEY_PAGE_DOWN,       { "PgDn",                   "Page Down" } },
        { GLFW_KEY_HOME,            { "Home",                   "Home" } },
        { GLFW_KEY_END,             { "End",                    "End" } },
        { GLFW_KEY_CAPS_LOCK,       { "CpsLk",                  "Caps Lock" } },
        { GLFW_KEY_SCROLL_LOCK,     { "ScrLk",                  "Scroll Lock" } },
        { GLFW_KEY_NUM_LOCK,        { "NumLk",                  "Num Lock" } },
        { GLFW_KEY_PRINT_SCREEN,    { "PrtScr",                 "Print Screen" } },
        { GLFW_KEY_PAUSE,           { "Pause",                  "Pause" } },
        { GLFW_KEY_F1,              { "F1",                     "F1" } },
        { GLFW_KEY_F2,              { "F2",                     "F2" } },
        { GLFW_KEY_F3,              { "F3",                     "F3" } },
        { GLFW_KEY_F4,              { "F4",                     "F4" } },
        { GLFW_KEY_F5,              { "F5",                     "F5" } },
        { GLFW_KEY_F6,              { "F6",                     "F6" } },
        { GLFW_KEY_F7,              { "F7",                     "F7" } },
        { GLFW_KEY_F8,              { "F8",                     "F8" } },
        { GLFW_KEY_F9,              { "F9",                     "F9" } },
        { GLFW_KEY_F10,             { "F10",                    "F10" } },
        { GLFW_KEY_F11,             { "F11",                    "F11" } },
        { GLFW_KEY_F12,             { "F12",                    "F12" } },
        { GLFW_KEY_F13,             { "F13",                    "F13" } },
        { GLFW_KEY_F14,             { "F14",                    "F14" } },
        { GLFW_KEY_F15,             { "F15",                    "F15" } },
        { GLFW_KEY_F16,             { "F16",                    "F16" } },
        { GLFW_KEY_F17,             { "F17",                    "F17" } },
        { GLFW_KEY_F18,             { "F18",                    "F18" } },
        { GLFW_KEY_F19,             { "F19",                    "F19" } },
        { GLFW_KEY_F20,             { "F20",                    "F20" } },
        { GLFW_KEY_F21,             { "F21",                    "F21" } },
        { GLFW_KEY_F22,             { "F22",                    "F22" } },
        { GLFW_KEY_F23,             { "F23",                    "F23" } },
        { GLFW_KEY_F24,             { "F24",                    "F24" } },
        { GLFW_KEY_F25,             { "F25",                    "F25" } },
        { GLFW_KEY_KP_0,            { "NumPd 0",                "Number Pad 0" } },
        { GLFW_KEY_KP_1,            { "NumPd 1",                "Number Pad 1" } },
        { GLFW_KEY_KP_2,            { "NumPd 2",                "Number Pad 2" } },
        { GLFW_KEY_KP_3,            { "NumPd 3",                "Number Pad 3" } },
        { GLFW_KEY_KP_4,            { "NumPd 4",                "Number Pad 4" } },
        { GLFW_KEY_KP_5,            { "NumPd 5",                "Number Pad 5" } },
        { GLFW_KEY_KP_6,            { "NumPd 6",                "Number Pad 6" } },
        { GLFW_KEY_KP_7,            { "NumPd 7",                "Number Pad 7" } },
        { GLFW_KEY_KP_8,            { "NumPd 8",                "Number Pad 8" } },
        { GLFW_KEY_KP_9,            { "NumPd 9",                "Number Pad 9" } },
        { GLFW_KEY_KP_DECIMAL,      { "NumPd .",                "Number Pad Decimal" } },
        { GLFW_KEY_KP_DIVIDE,       { "NumPd /",                "Number Pad Divide" } },
        { GLFW_KEY_KP_MULTIPLY,     { "NumPd *",                "Number Pad Multiply" } },
        { GLFW_KEY_KP_SUBTRACT,     { "NumPd -",                "Number Pad Subtract" } },
        { GLFW_KEY_KP_ADD,          { "NumPd +",                "Number Pad Add" } },
        { GLFW_KEY_KP_ENTER,        { "NumPd Enter",            "Number Pad Enter" } },
        { GLFW_KEY_KP_EQUAL,        { "NumPd =",                "Number Pad Equal" } },
        { GLFW_KEY_LEFT_SHIFT,      { "LShift",                 "Left Shift" } },
        { GLFW_KEY_LEFT_CONTROL,    { "LCtrl",                  "Left Ctrl" } },
        { GLFW_KEY_LEFT_ALT,        { "LAlt",                   "Left Alt" } },        
        { GLFW_KEY_RIGHT_SHIFT,     { "RShift",                 "Right Shift" } },
        { GLFW_KEY_RIGHT_CONTROL,   { "RCtrl",                  "Right Ctrl" } },
        { GLFW_KEY_RIGHT_ALT,       { "RAlt",                   "Right Alt" } },
        { GLFW_KEY_MENU,            { "Menu",                   "Menu" } },
#ifdef CFG_WINDOWS
        { GLFW_KEY_LEFT_SUPER,      { "LWindows",               "Left Windows" } },
        { GLFW_KEY_RIGHT_SUPER,     { "RWindows",               "Right Windows" } }
#elseif CGG_MACOSX
        { GLFW_KEY_LEFT_SUPER,      { "LCmd",                   "Left Command" } },
        { GLFW_KEY_RIGHT_SUPER,     { "RCmd",                   "Right Command" } }
#elseif CGG_LINUX
        { GLFW_KEY_LEFT_SUPER,      { "LSuper",                 "Left Super" } },
        { GLFW_KEY_RIGHT_SUPER,     { "RSuper",                 "Right Super" } }
#endif
    };
}
