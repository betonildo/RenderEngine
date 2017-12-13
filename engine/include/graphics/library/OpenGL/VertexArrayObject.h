#ifndef VERTEXARRAYOBJECT_H
#define VERTEXARRAYOBJECT_H

#include "typedefs.h"
#include <array>

class VertexBuffer;

class VertexArrayObject {

public:
    static const uint kMaxBuffersPerVAO = 7;

    VertexArrayObject();

    void addVertexBuffer(VertexBuffer* buffer);
    void bind();
    void unbind();

private:
    uint mLocation;
    uint mBufferCounter = 0;
    std::array< VertexBuffer*, VertexArrayObject::kMaxBuffersPerVAO > mBuffers;
};

#endif /*VERTEXARRAYOBJECT_H*/