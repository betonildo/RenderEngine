#ifndef VERTEX_H
#define VERTEX_H

#include "OSExport.h"
#include "LinearMath.h"

#pragma pack(push, 0)
class ENGINE_API Vertex {

public:
    Vector3 position;
    Vector3 normal;
    Vector2 uv;

    // TODO: INCLUDE CALCULATIONS TO OFFSETS IN THIS STRUCTURE

};
#pragma pack(pop)

#endif /*VERTEX_H*/