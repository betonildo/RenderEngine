#ifndef BUFFER_H
#define BUFFER_H

#include "typedefs.h"

class GraphicLibrary;

class Buffer {

public:
    enum class Type {
        ArrayBuffer, ElementArray
    };
    
    struct Format {
        uint index;
        uint size;
        uint type;
        bool normalized;
        uint stride;
        uint pointer;
    };

    Buffer(GraphicLibrary* gl, Buffer::Type type);
    void setVertexFormat(Buffer::Format format);
    void setLocation(uint location);
    void setData(byte* data, uint length);
    void bind();
    void unbind();

private:
    GraphicLibrary* gl;
    uint mLocation;
    Buffer::Type mType;
    Buffer::Format mFormat;
    byte* mData;
    uint mDataLength;
};

#endif /*BUFFER_H*/