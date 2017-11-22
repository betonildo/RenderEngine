#ifndef RAYCASTHIT_H
#define RAYCASTHIT_H

#include "LinearMath.h"
#include "typedefs.h"

struct Object;


struct RaycastHit {
    float closest;
    const Object* object;
    Vector2 uv;
    uint index;
};
#endif /*RAYCASTHIT_H*/