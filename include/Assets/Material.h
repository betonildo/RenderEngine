#include "renderer_local_includes.h"
#include "Asset.h"
#include "Shader.h"
#include "Texture.h"
#include "FileUtils.h"

class Asset;
class Shader;
class Texture;
class FileUtils;

#ifndef MATERIAL_H
#define MATERIAL_H

struct MaterialEntry {
    std::string type;
    std::string name;
    std::string value;
};

class Material : public Asset {

public:
    virtual void load(const char* relativePath);
    void save();

    void use();
    void setTexture(const char* uniform, Texture t);
    void setVector2(const char* uniform, glm::vec2 v);
    void setVector3(const char* uniform, glm::vec3 v);
    void setVector4(const char* uniform, glm::vec4 v);
    void setMatrix4(const char* uniform, glm::mat4 m);

    Shader m_shader;
    
private:

    std::string m_relativePath;

    std::map<unsigned int, Texture> m_textures;
    std::map<unsigned int, glm::vec2> m_vectors2;
    std::map<unsigned int, glm::vec3> m_vectors3;
    std::map<unsigned int, glm::vec4> m_vectors4;
    std::map<unsigned int, glm::mat4> m_matrices4;

    std::vector<std::string>& m_getMatLines(std::string& matSource);
    MaterialEntry m_getMaterialEntry(std::string& materialLine);
    std::vector<std::string>& m_splitLineIntoFields(std::string& line);
};

#endif /*MATERIAL_H*/
