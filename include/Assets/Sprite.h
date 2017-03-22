#include "Assets/Asset.h"
#include "Assets/Texture.h"
#include "Assets/Material.h"
#include "SpriteVertex.h"

#ifndef SPRITE_H
#define SPRITE_H

class Texture;
class Material;
class SpriteVertex;
class SpriteMeshRenderer;

class Sprite : public Asset {

public:
    Sprite();
    virtual void load(const char* relativePath);

private:
    std::vector<Vector3> m_vertices;
    std::vector<Vector3> m_normals;
    std::vector<Vector2> m_uvs;
    std::vector<unsigned short> m_indexes;
    Material m_material;
    unsigned int m_vertexVBO;
    unsigned int m_normalVBO;
    unsigned int m_uvVBO;
    unsigned int m_elementVBO;

    void m_uploadToGPU();
    friend class SpriteMeshRenderer;
};

#endif /*SPRITE_H*/