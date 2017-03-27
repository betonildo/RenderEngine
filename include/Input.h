#ifndef INPUT_H
#define INPUT_H

#include "WindowManager.h"

struct MousePoint {
    int x, y;
};

class Input {

public:
    static MousePoint getPointer();
    static MousePoint* getPointers();
    static bool leftButtonPressed();
    static bool rightButtonPressed();
    static bool keyPressed(const std::string& keyname);
    static bool keyReleased(const std::string& keyname);
    static bool keyUp(const std::string& keyname);
    static bool keyDown(const std::string& keyname);

private:
    static Input* m_instance;

    MousePoint m_pointers[5];
    bool m_leftWasPressed;
    bool m_rightWasPressed;

    std::string m_keyname;
    bool m_keypressed;
    bool m_keyreleased;
    bool m_keyup;
    bool m_keydown;

    inline Input() {

    }

    static void clearLastInputs();

    friend class WindowManager;
};

#endif /*INPUT_H*/