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

private:
    static Input* m_instance;

    MousePoint m_pointers[5];
    bool m_leftWasPressed;
    bool m_rightWasPressed;

    inline Input() {

    }

    static void clearLastInputs();

    friend class WindowManager;
};

#endif /*INPUT_H*/