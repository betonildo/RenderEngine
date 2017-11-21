#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef unsigned char byte;
typedef unsigned int uint;
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

#endif /*TYPEDEFS_H*/