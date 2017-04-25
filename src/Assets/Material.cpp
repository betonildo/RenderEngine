#include "Assets/Material.h"

void Material::load(const char* relativePath) {
    // read line by line with a TYPE KEY=VALUE
    /*
    glm::mat4 MVP={{}}
    Texture MainTexture = "<path/to/image>"
    glm::vec3 color = {1, 0.5, 0.9, 1}
    */
    m_relativePath = relativePath;

    std::string matSource = FileUtils::readAllText(relativePath);

    auto matLines = m_getMatLines(matSource);
    for(auto line : matLines) {
        
        auto entry = m_getMaterialEntry(line);

        if (entry.type == "Shader") {
            m_shader.load(entry.value.c_str());
        }
        else if (entry.type == "Texture") {
            Texture t;
            t.load(entry.value.c_str());
            setTexture(entry.name.c_str(), t);
        }
    }
}

void Material::use() {
    m_shader.use();

    //TODO : maybe create an asset abstraction to get value and TYPE
    //       and the shader selects what glUniform{t} to apply
    unsigned int index = 0;
    for(auto uniform : m_textures) {
        uniform.second.setTextureIndex(index++);
        m_shader.setTexture(uniform.first, uniform.second);
    }

    for(auto uniform : m_vectors2) {
        m_shader.setVector2(uniform.first, uniform.second);
    }

    for(auto uniform : m_vectors3) {
        m_shader.setVector3(uniform.first, uniform.second);
    }

    for(auto uniform : m_vectors4) {
        m_shader.setVector4(uniform.first, uniform.second);
    }

    for(auto uniform : m_matrices4) {
        m_shader.setMatrix4(uniform.first, uniform.second);
    }
}

void Material::setTexture(const char* uniform, Texture t) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);    
    m_textures[uniformLocation] = t;
}

void Material::setVector2(const char* uniform, glm::vec2 v) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    m_vectors2[uniformLocation] = v;
}

void Material::setVector3(const char* uniform, glm::vec3 v) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    m_vectors3[uniformLocation] = v;
}

void Material::setVector4(const char* uniform, glm::vec4 v) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    m_vectors4[uniformLocation] = v;
}

void Material::setMatrix4(const char* uniform, glm::mat4 m) {
    unsigned int uniformLocation = m_shader.getUniformLocation(uniform);
    m_matrices4[uniformLocation] = m;
}


std::vector<std::string>& Material::m_getMatLines(std::string& matSource) {

    std::vector<std::string>* lines = new std::vector<std::string>;
    std::string currentLine = "";
    for(int i = 0; i < matSource.size(); i++) {

        unsigned char c = matSource[i];
        if (c == '\n' || i >= matSource.size() - 1) {
            currentLine += '\0';
            lines->push_back(currentLine);
            currentLine = "";
        }
        else {
            currentLine += c;
        }
    }

    return *lines;
}

MaterialEntry Material::m_getMaterialEntry(std::string& materialLine) {

    MaterialEntry entry;

    std::vector<std::string> fields = m_splitLineIntoFields(materialLine);

    entry.type = fields[0];
    entry.name = fields[1];
    entry.value = fields[2];
    
    return entry;
}

std::vector<std::string>& Material::m_splitLineIntoFields(std::string& line) {
    
    std::vector<std::string>* fields = new std::vector<std::string>;
    std::string current = "";

    for(int i = 0; i < line.size(); i++) {
        unsigned char c = line[i];
        if (c != ' ') {
            current += c;
        }
        else {
            fields->push_back(current);
            current = "";
        }
    }
    
    fields->push_back(current);
    current = "";

    return *fields;
}