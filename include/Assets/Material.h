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

class Asset;
class Shader;
class Texture;
struct Vector2;
struct Vector3;
struct Vector4;
class Matrix3;
class Matrix4;

class Material : public Asset {

public:
    virtual void load(const char* relativePath);

    void setShader(Shader* shader);
    void use();
    void setTexture(const char* uniform, Texture texture);
    void setVector2(const char* uniform, Vector2 v);
    void setVector3(const char* uniform, Vector3 v);
    void setVector4(const char* uniform, Vector4 v);
    void setMatrix3(const char* uniform, Matrix3 m3);
    void setMatrix4(const char* uniform, Matrix4 m4);

private:
    Shader* m_shader;

};

#endif /*MATERIAL_H*/
