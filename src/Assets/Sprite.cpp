#include "Assets/Sprite.h"

Sprite::Sprite() {
    glGenBuffers(1, &m_vertexVBO);
    // glGenBuffers(1, &m_normalVBO);
    // glGenBuffers(1, &m_uvVBO);
    glGenBuffers(1, &m_elementVBO);

    SpriteVertex a = {
        Vector3(-0.5, -0.5, 0),
        Vector3(0, 0, 1),
        Vector2(0, 0)
    };

    SpriteVertex b = {
        Vector3(0.5, -0.5, 0),
        Vector3(0, 0, 1),
        Vector2(1, 0)
    };

    SpriteVertex c = {
        Vector3(0.5, 0.5, 0),
        Vector3(0, 0, 1),
        Vector2(1, 1)
    };

    SpriteVertex d = {
        Vector3(-0.5, 0.5, 0),
        Vector3(0, 0, 1),
        Vector2(0, 1)
    };

    m_vertices.push_back(a);
    m_vertices.push_back(b);
    m_vertices.push_back(c);
    m_vertices.push_back(d);

    m_indexes = {0, 1, 2, 3};
}

void Sprite::load(const char* relativePath) {
    m_material.load("resources/test/Materials/Default_SpriteMaterial.mat");
    m_uploadToGPU();
}

void Sprite::m_uploadToGPU() {
    // Load it into a VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(SpriteVertex), &m_indexes[0], GL_STATIC_DRAW);

    // Generate a buffer for the indices as well
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementVBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexes.size() * sizeof(unsigned short), &m_indexes[0], GL_STATIC_DRAW);
}