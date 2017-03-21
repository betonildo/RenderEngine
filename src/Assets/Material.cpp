#include "Assets/Material.h"

void Material::load(const char* relativePath) {
    // read line by line with a TYPE KEY=VALUE
    /*
    Matrix4 MVP={{}}
    Texture MainTexture = "<path/to/image>"
    Vector3 color = {1, 0.5, 0.9, 1}
    */
    m_relativePath(relativePath);

    std::vector<std::string> matLines = FileUtils::readAllLinesAsText(m_relativePath);
        
}

void Material::use() {
    m_shader.use();

    //TODO : maybe create an asset abstraction to get value and TYPE
    //       and the shader selects what glUniform{t} to apply
    for(auto uniform : m_textures) {
        m_shader.setUniformv(uniform->first, uniform->second);
    }

    for(auto uniform : m_vectors2) {
        m_shader.setUniformv(uniform->first, uniform->second);
    }

    for(auto uniform : m_vectors3) {
        m_shader.setUniformv(uniform->first, uniform->second);
    }

    for(auto uniform : m_vectors4) {
        m_shader.setUniformv(uniform->first, uniform->second);
    }

    for(auto uniform : m_matrices3) {
        m_shader.setUniformv(uniform->first, uniform->second);
    }

    for(auto uniform : m_matrices4) {
        m_shader.setUniformv(uniform->first, uniform->second);
    }
}

void Material::setTexture(const char* uniform, Texture texture, unsigned int index) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    texture.setTextureIndex(index);
    m_textures[uniformLocation] = texture;
}

void Material::setVector2(const char* uniform, Vector2 v) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    m_vectors2[uniformLocation] = v;
}

void Material::setVector3(const char* uniform, Vector3 v) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    m_vectors3[uniformLocation] = v;
}

void Material::setVector4(const char* uniform, Vector4 v) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    m_vectors4[uniformLocation] = v;
}

void Material::setMatrix3(const char* uniform, Matrix3 m3) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    m_matrices3[uniformLocation] = m;
}

void Material::setMatrix4(const char* uniform, Matrix4 m4) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    m_matrices4[uniformLocation] = m;
}
