#include "Assets/Sprite.h"

Sprite::Sprite() {
    glGenBuffers(1, &m_vertexVBO);
    // glGenBuffers(1, &m_normalVBO);
    // glGenBuffers(1, &m_uvVBO);
    glGenBuffers(1, &m_elementVBO);
}

void Sprite::load(const char* relativePath) {
    m_material.load("test/Materials/Default_SpriteMaterial.mat");
}

void Sprite::m_uploadToGPU() {
    // Load it into a VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(SpriteVexter), &indexed_vertices[0], GL_STATIC_DRAW);

    // Generate a buffer for the indices as well
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementVBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexes.size() * sizeof(unsigned short), &m_indexes[0], GL_STATIC_DRAW);
}