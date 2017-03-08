#ifndef INPUT_H
#define INPUT_H

#include "WindowManager.h"

struct Point {
    float x, y;
};

class Input {

public:
    static Point getPointer();
    static Point* getPointers();
    static bool leftButtonPressed();
    static bool rightButtonPressed();

private:
    static Input* m_instance;

    Point m_pointers[5];
    bool m_leftWasPressed;
    bool m_rightWasPressed;

    inline Input() {

    }

    static void clearLastInputs();

    friend class WindowManager;
};

#endif /*INPUT_H*/