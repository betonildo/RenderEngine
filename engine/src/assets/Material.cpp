#include "assets/Material.h"
#include "graphics/ShaderProgram.h"

Material::Material() {

}

const std::map<unsigned int, Vector3>& Material::getUniformsVector3() const {
    return mUniformsVector3;
}

const std::map<unsigned int, Vector2>& Material::getUniformsVector2() const {
    return mUniformsVector2;
}

const std::map<unsigned int, Matrix4>& Material::getUniformsMatrix4() const {
    return mUniformsMatrix4;
}

void Material::setUniform(const std::string& name, Vector3 v) {
    
}

void Material::setUniform(const std::string& name, Vector2 v) {

}

void Material::setUniform(const std::string& name, Matrix4 m) {

}

void Material::setShaderProgram(ShaderProgram shaderProgram) {
    
}