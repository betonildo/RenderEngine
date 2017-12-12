#ifndef PIXELCOLOR_H
#define PIXELCOLOR_H

#include "typedefs.h"

struct PixelColor{
    union{
        struct {
            byte r, g, b, a;
        };

        byte data[4];
    };

    inline byte& operator[](byte i) {
        return data[i];
    }
};

#endif /*PIXELCOLOR_H*/