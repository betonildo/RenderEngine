#ifndef RAYTRACERATTRIBUTES_H
#define RAYTRACERATTRIBUTES_H

#include "LinearMath.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include <array>
#include <vector>
#include <limits>
#include <cfloat>

#include "graphics/TextureFormat.h"
#include "typedefs.h"
#include "graphics/PixelColor.h"

float Infinity = std::numeric_limits<float>::max();

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
    byte* data;
    TextureFormat format;

    inline void sample(Color4& colorout, uint i, uint j) const {
        byte* rgba = &data[i * format.channels * format.width + j];
        colorout.r = rgba[0] / 256.0f;
        colorout.g = rgba[1] / 256.0f;
        colorout.b = rgba[2] / 256.0f;
        colorout.a = rgba[3] / 256.0f;
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