#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "graphics/VertexFormat.h"

struct VertexBuffer {
    uint vbo;
    uint location;
    VertexFormat format;
};


#endif /*VERTEXBUFFER_H*/