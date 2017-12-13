#ifndef RAYCASTHIT_H
#define RAYCASTHIT_H

#include "LinearMath.h"
#include "typedefs.h"

struct RayTracerObject;


struct RaycastHit {
    float closest;
    const RayTracerObject* object;
    Vector2 uv;
    uint index;
};
#endif /*RAYCASTHIT_H*/