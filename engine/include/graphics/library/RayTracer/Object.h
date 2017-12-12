#ifndef OBJECT_H
#define OBJECT_H

#include "graphics/ElementFormat.h"
#include "LinearMath.h"
#include "OSExport.h"

class VertexBuffer;
class Material;
class IndexBuffer;
class TextureBuffer;
struct RaycastHit;
class Ray;
struct Triangle;

static float kEpsilon = 1e-8;

struct ENGINE_API Object
{

    // TODO: Setup uv0, uv1, ... with textures0, 1, ... units like an index activation of the array

    Material* material;
    TextureBuffer* texture[4];
    VertexBuffer* positions;
    VertexBuffer* normals;
    VertexBuffer* uvs;
    IndexBuffer* indices;
    ElementFormat format;
    Matrix4 World;

    Object();

    bool intersect(const Ray& ray, RaycastHit& hit);
    bool intersectTriangle(const Triangle& triangle, const Ray& ray, RaycastHit& hit);
    void getSurfaceProperties(const uint32_t &index, const Vector2 &uv, Vector3 &N, Vector2 &st) const;
};

#endif /*OBJECT_H*/