#include "Assets/Sprite.h"

Sprite::Sprite() {
    glGenBuffers(1, &m_vertexVBO);
    glGenBuffers(1, &m_normalVBO);
    glGenBuffers(1, &m_uvVBO);
    glGenBuffers(1, &m_elementVBO);

    m_vertices.push_back(glm::vec3(-1,-1, 0));
    m_vertices.push_back(glm::vec3( 1,-1, 0));
    m_vertices.push_back(glm::vec3( 1, 1, 0));
    m_vertices.push_back(glm::vec3(-1, 1, 0));
    
    m_normals = {
        glm::vec3(0, 0, 1),
        glm::vec3(0, 0, 1),
        glm::vec3(0, 0, 1),
        glm::vec3(0, 0, 1)
    };

    m_uvs = {
        glm::vec2(0, 0),
        glm::vec2(1, 0),
        glm::vec2(1, 1),
        glm::vec2(0, 1)
    };

    m_indexes.push_back(0);
    m_indexes.push_back(1);
    m_indexes.push_back(2);
    m_indexes.push_back(2);
    m_indexes.push_back(3);
    m_indexes.push_back(0);
}

void Sprite::load(const char* relativePath) {
    m_material.load("resources/test/Materials/Default_SpriteMaterial.mat");
    m_uploadToGPU();
}

void Sprite::m_uploadToGPU() {
    // Load it into a VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(glm::vec3), &m_vertices[0], GL_STATIC_DRAW);

    // Load it into a VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_normalVBO);
    glBufferData(GL_ARRAY_BUFFER, m_normals.size() * sizeof(glm::vec3), &m_normals[0], GL_STATIC_DRAW);

        // Load it into a VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_uvVBO);
    glBufferData(GL_ARRAY_BUFFER, m_uvs.size() * sizeof(glm::vec2), &m_uvs[0], GL_STATIC_DRAW);

    // Generate a buffer for the indices as well
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementVBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexes.size() * sizeof(unsigned short), &m_indexes[0], GL_STATIC_DRAW);
}