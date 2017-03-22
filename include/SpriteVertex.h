#include "Vector2.h"
#include "Vector3.h"

#ifndef SPRITEVERTEX_H
#define SPRITEVERTEX_H

#pragma pack(push, 0)
class SpriteVertex {

public:
    Vector3 position;
    Vector3 normal;
    Vector2 uv;

};
#pragma pack(pop)

#endif /*SPRITEVERTEX_H*/