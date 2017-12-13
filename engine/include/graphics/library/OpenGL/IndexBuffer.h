#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include "graphics/ElementFormat.h"

class IndexBuffer {

public:
    uint ibo;
    void *elementsPointer;
    ElementFormat format;
};

#endif /*INDEXBUFFER_H*/