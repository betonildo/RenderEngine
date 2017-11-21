#ifndef INPUT_H
#define INPUT_H

#include "OSExport.h"
#include <functional>
#include <vector>

class ENGINE_API Input {

public:
    enum class Key {
        ArrowUp,
        ArrowDown,
        ArrowLeft,
        ArrowRight,
        W,
        A,
        S,
        D
    };
    

    static void addKeydownListener(std::function<void(Key)> onKeyDown);
    static void dispatchKeydownEvent(Key key);

};

#endif /*INPUT_H*/