#ifndef MATERIAL_H
#define MATERIAL_H

#include "OSExport.h"
#include "LinearMath.h"
#include "assets/Asset.h"
#include "assets/Texture.h"
#include <map>
#include <string>

class GraphicLibrary;

class ENGINE_API Material : public Asset {

public:

    Material();

    Texture mainTexture;
    float shininess;
    Color specular;
    Color diffuse;
    float alpha;
    float reflection;
    

    const std::map<unsigned int, Vector3>& getUniformsVector3() const;
    const std::map<unsigned int, Vector2>& getUniformsVector2() const;
    const std::map<unsigned int, Matrix4>& getUniformsMatrix4() const;

    void setUniform(const std::string& name, Vector3 v);
    void setUniform(const std::string& name, Vector2 v);
    void setUniform(const std::string& name, Matrix4 m);

    void setShaderProgram(uint shaderProgram);

    void bind();
    void unbind();

private:
    std::map<unsigned int, Vector3> mUniformsVector3;
    std::map<unsigned int, Vector2> mUniformsVector2;
    std::map<unsigned int, Matrix4> mUniformsMatrix4;

    uint mShaderProgram;

    bool mMatrix4CacheValid;
    bool mVector3CacheValid;
    bool mVector2CacheValid;

	GraphicLibrary* gl;
};

#endif /*MATERIAL_H*/