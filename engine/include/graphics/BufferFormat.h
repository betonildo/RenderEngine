#ifndef BUFFERFORMAT_H
#define BUFFERFORMAT_H

#include "typedefs.h"

enum class BufferType {
    ArrayBuffer, ElementArray
};

struct BufferFormat{
    BufferType type;
    uint location;


};


#endif /*BUFFERFORMAT_H*/