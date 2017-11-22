#ifndef RAYTRACERATTRIBUTES_H
#define RAYTRACERATTRIBUTES_H

#include "LinearMath.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include <array>
#include <vector>
#include <climits>
#include <cfloat>

#include "graphics/TextureFormat.h"
#include "typedefs.h"

static constexpr float Infinity = std::numeric_limits<float>::max();

struct PixelColor{
    union{
        struct {
            byte r, g, b, a;
        };

        byte data[4];
    };

    inline byte& operator[](byte i) {
        return data[i];
    }
};

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
        byte* rgba = &data[i + format.width * j];
        colorout.r = rgba[0] / 255;
        colorout.g = rgba[1] / 255;
        colorout.b = rgba[2] / 255;
        colorout.a = rgba[3] / 255;
    }

    // inline void sample(Color& colorout, uint i, uint j) const {
    //     byte* rgb = &data[i + format.width * j];
    //     colorout.r = rgb[0] / 255;
    //     colorout.g = rgb[1] / 255;
    //     colorout.b = rgb[2] / 255;
    // }
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