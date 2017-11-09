#ifndef BUFFER_H
#define BUFFER_H

#include "OSExport.h"

class GraphicLibrary;

class ENGINE_API Buffer {

public:
    Buffer(unsigned int bufferLocation);
    void attachData(void* data, unsigned int length);
    void bind();
    void unbind();

private:
    GraphicLibrary* gl;
    void* mData;
    unsigned int mDataLength;
    unsigned int mBufferLocation;

};

#endif /*BUFFER_H*/