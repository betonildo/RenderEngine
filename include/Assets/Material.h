#ifndef MATERIAL_H
#define MATERIAL_H

#include "Asset.h"
#include "Shader.h"
#include "Texture.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "FileUtils.h"

class Asset;
class Shader;
class Texture;
struct Vector2;
struct Vector3;
struct Vector4;
class Matrix3;
class Matrix4;
class FileUtils;

class Material : public Asset {

public:
    virtual void load(const char* relativePath);
    void save();

    void use();
    void setTexture(const char* uniform, Texture texture, unsigned int index);
    void setVector2(const char* uniform, Vector2 v);
    void setVector3(const char* uniform, Vector3 v);
    void setVector4(const char* uniform, Vector4 v);
    void setMatrix3(const char* uniform, Matrix3 m3);
    void setMatrix4(const char* uniform, Matrix4 m4);

private:
    Shader m_shader;

    std::string m_relativePath;

    std::map<std::string, unsigned int> m_location_textures;
    std::map<std::string, unsigned int> m_location_vectors2;
    std::map<std::string, unsigned int> m_location_vectors3;
    std::map<std::string, unsigned int> m_location_vectors4;
    std::map<std::string, unsigned int> m_location_matrices3;
    std::map<std::string, unsigned int> m_location_matrices4;

    std::map<unsigned int, Texture> m_textures;
    std::map<unsigned int, Vector2> m_vectors2;
    std::map<unsigned int, Vector3> m_vectors3;
    std::map<unsigned int, Vector4> m_vectors4;
    std::map<unsigned int, Matrix3> m_matrices3;
    std::map<unsigned int, Matrix4> m_matrices4;
};

#endif /*MATERIAL_H*/
