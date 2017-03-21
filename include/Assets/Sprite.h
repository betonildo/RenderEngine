#include "Assets/Asset.h"
#include "Assets/Texture.h"
#include "Assets/Material.h"
#include "SpriteVertex.h"

#ifndef SPRITE_H
#define SPRITE_H

class Sprite : public Asset {

public:
    Sprite();
    virtual void load(const char* relativePath);

private:
    std::vector<SpriteVertex> m_vertices;
    std::vector<unsigned short> m_indexes;
    Material m_material;
    unsigned int m_vertexVBO;
    // unsigned int m_normalVBO;
    // unsigned int m_uvVBO;
    unsigned int m_elementVBO;

    void m_uploadToGPU();

};

#endif /*SPRITE_H*/