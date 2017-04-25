#include "renderer_local_includes.h"

#ifndef SPRITEVERTEX_H
#define SPRITEVERTEX_H

#pragma pack(push, 0)
class SpriteVertex {

public:
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;

};
#pragma pack(pop)

#endif /*SPRITEVERTEX_H*/