#ifndef OBJECT_H
#define OBJECT_H

#include "graphics/ElementFormat.h"
#include "LinearMath.h"

class VertexBuffer;
class Material;
class IndexBuffer;
class TextureBuffer;

struct Object
{
    struct Hit {
        const Object* object;
        Vector2 uv;
        float near;
        uint index;
    };

    static constexpr float kEpsilon = 1e-8;

    // TODO: Setup uv0, uv1, ... with textures0, 1, ... units like an index activation of the array

    const Material *material;
    TextureBuffer* texture;
    VertexBuffer* positions;
    VertexBuffer* normals;
    VertexBuffer* uvs;
    IndexBuffer* indices;
    ElementFormat format;
    Matrix4 World;

    inline bool intersect(const Ray& ray, Hit& hit) {

        for (uint i = 0; i < indices->data.size(); i+=3) {

            uint iv0 = indices->data[i + 0];
            uint iv1 = indices->data[i + 1];
            uint iv2 = indices->data[i + 2];

            const Vector3 v0 = World * Vector4(positions->dataVector3[iv0], 1);
            const Vector3 v1 = World * Vector4(positions->dataVector3[iv1], 1);
            const Vector3 v2 = World * Vector4(positions->dataVector3[iv2], 1);

            if (intersectTriangle({v0, v1, v2}, ray, hit)) {
                hit.object = this;
                hit.index = i;
                return true;
            }
        }

        return false;
    }

    inline bool intersectTriangle(const Triangle& triangle, const Ray& ray, Hit& hit) {
        Vector3 v0v1 = triangle.v1 - triangle.v0; 
        Vector3 v0v2 = triangle.v2 - triangle.v0; 
        Vector3 pvec = Math::cross(ray.direction, v0v2); 
        float det = Math::dot(v0v1, pvec); 

        // ray and triangle are parallel if det is close to 0
        if (fabs(det) < kEpsilon) return false; 

        float invDet = 1 / det; 
    
        Vector3 tvec = ray.origin - triangle.v0; 
        hit.uv.x = Math::dot(tvec, pvec) * invDet; 
        if (hit.uv.x < 0 || hit.uv.x > 1) return false; 
    
        Vector3 qvec = Math::cross(tvec, v0v1); 
        hit.uv.y = Math::dot(ray.direction, qvec) * invDet; 
        if (hit.uv.y < 0 || hit.uv.x + hit.uv.y > 1) return false; 
    
        hit.near = Math::dot(v0v2, qvec) * invDet;
    
        return true;
    }

    void getSurfaceProperties(const uint32_t &index, const Vector2 &uv, Vector3 &N, Vector2 &st) const 
    { 
        uint iv0 = indices->data[index + 0];
        uint iv1 = indices->data[index + 1];
        uint iv2 = indices->data[index + 2];
        const Vector3 v0 = positions->dataVector3[iv0]; 
        const Vector3 v1 = positions->dataVector3[iv1];
        const Vector3 v2 = positions->dataVector3[iv2];
        Vector3 e0 = Math::normalize(v1 - v0);
        Vector3 e1 = Math::normalize(v2 - v1);
        N = Math::normalize(Math::cross(e0, e1));
        const Vector2 st0 = uvs->dataVector2[iv0];
        const Vector2 st1 = uvs->dataVector2[iv1];
        const Vector2 st2 = uvs->dataVector2[iv2];
        st = st0 * (1 - uv.x - uv.y) + st1 * uv.x + st2 * uv.y;
    } 
};

#endif /*OBJECT_H*/