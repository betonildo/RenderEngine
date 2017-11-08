#ifndef BUFFER_H
#define BUFFER_H

#include "OSExport.h"

class ENGINE_API Buffer {

public:
    enum class BufferType {
        Array, Element
    };

    Buffer(unsigned int bufferLocation);
    void attachData(void* data, unsigned int length);
    void setType(BufferType bufferType);
    void bind();
    void unbind();

private:
    BufferType mBufferType;
    void* mData;
    unsigned int mDataLength;
    unsigned int mBufferLocation;

};

#endif /*BUFFER_H*/