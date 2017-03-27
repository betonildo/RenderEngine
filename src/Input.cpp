#include "Input.h"

Input* Input::m_instance = new Input();

MousePoint Input::getPointer() {
    return Input::m_instance->m_pointers[0];
}

MousePoint* Input::getPointers() {
    return Input::m_instance->m_pointers;
}

bool Input::leftButtonPressed() {
    return Input::m_instance->m_leftWasPressed;
}

bool Input::rightButtonPressed() {
    return Input::m_instance->m_rightWasPressed;
}

bool Input::keyPressed(const std::string& keyname) {
    return Input::m_instance->m_keypressed && keyname == Input::m_instance->m_keyname;
}

bool Input::keyReleased(const std::string& keyname) {
    return Input::m_instance->m_keyreleased && keyname == Input::m_instance->m_keyname;
}

bool Input::keyUp(const std::string& keyname) {
    return !Input::m_instance->m_keydown && 
            Input::m_instance->m_keyup && 
            keyname == Input::m_instance->m_keyname;
}

bool Input::keyDown(const std::string& keyname) {
    return !Input::m_instance->m_keyup &&
            Input::m_instance->m_keydown && 
            keyname == Input::m_instance->m_keyname;
}

void Input::clearLastInputs() {

    // Input::m_instance->m_pointers[5];
    Input::m_instance->m_leftWasPressed = false;
    Input::m_instance->m_rightWasPressed = false;
    Input::m_instance->m_keydown = false;
    Input::m_instance->m_keyup = false;
    Input::m_instance->m_keypressed = false;
    Input::m_instance->m_keyreleased = false;
    //memset(Input::m_instance, 0, sizeof(Input));
}

