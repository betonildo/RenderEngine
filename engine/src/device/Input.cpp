#include "device/Input.h"

std::vector< std::function< void(Input::Key) > > mOnKeydownListeners;

void Input::addKeydownListener(std::function<void(Input::Key)> onKeydown) {
    mOnKeydownListeners.push_back(onKeydown);
}

void Input::dispatchKeydownEvent(Key key) {
    for (auto& onKeydown : mOnKeydownListeners)
        onKeydown(key);
}