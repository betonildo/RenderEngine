#ifndef RAYTRACERATTRIBUTES_H
#define RAYTRACERATTRIBUTES_H

#include "LinearMath.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include <array>
#include <vector>
#include "graphics/TextureFormat.h"
#include "typedefs.h"

constexpr float Infinity = std::numeric_limits<float>::max();

struct IndexBuffer
{
    std::vector<unsigned int> data;
    ElementFormat format;
};

struct VertexBuffer
{
    std::vector<Vector3> dataVector3;
    std::vector<Vector2> dataVector2;
    VertexFormat format;
};

struct TextureBuffer
{
    Color4* data;
    uint width;
    uint height;

    inline const Color4& operator()(uint i, uint j) {
        return data[i + width * j];
    }
};

struct Triangle {
    Vector3 v0, v1, v2;
};

struct LightsConfig
{
    const Light *lights;
    uint lightCount;
};

struct IndicesConfig
{
    const uint *indices;
    uint indicesCount;
};

struct Ray {
    Vector3 origin, direction;
};

#endif /*RAYTRACERATTRIBUTES_H*/