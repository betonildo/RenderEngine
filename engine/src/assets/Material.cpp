#include "assets/Material.h"
#include "graphics/ShaderProgram.h"
#include "graphics/GraphicLibrary.h"
#include "graphics/GraphicLibrarySingleton.h"

Material::Material() {
    mMatrix4CacheValid = false;
    mVector3CacheValid = false;
    mVector2CacheValid = false;
	gl = GraphicLibrarySingleton::getInstance();
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
    if (mShaderProgram) {
        mVector3CacheValid = false;
		const char* uniformName = name.c_str();
        unsigned int uniformLocation = gl->getUniformLocation(mShaderProgram, uniformName);
        mUniformsVector3[uniformLocation] = v;
    }
}

void Material::setUniform(const std::string& name, Vector2 v) {
    if (mShaderProgram) {
        mVector2CacheValid = false;
		const char* uniformName = name.c_str();
        unsigned int uniformLocation = gl->getUniformLocation(mShaderProgram, uniformName);
        mUniformsVector2[uniformLocation] = v;
    }
}

void Material::setUniform(const std::string& name, Matrix4 m) {
    if (mShaderProgram) {
        mMatrix4CacheValid = false;
		const char* uniformName = name.c_str();
        unsigned int uniformLocation = gl->getUniformLocation(mShaderProgram, uniformName);
        mUniformsMatrix4[uniformLocation] = m;
    }
}

void Material::setShaderProgram(uint shaderProgram) {
	mShaderProgram = shaderProgram;
}

void Material::bind() {
	if (mShaderProgram) gl->bindShaderProgram(mShaderProgram);

    // ONLY SET TO SHADER NEW VALUES
    if (!mMatrix4CacheValid) {
        mMatrix4CacheValid = true;
        for (auto uniform : mUniformsMatrix4)
            gl->setMatrix4(uniform.first, uniform.second);
    }

    if (!mVector2CacheValid) {
        mVector2CacheValid = true;
        for (auto uniform : mUniformsVector2)
            gl->setVector2(uniform.first, uniform.second);
    }

    if (!mVector3CacheValid) {
        mVector3CacheValid = true;
        for (auto uniform : mUniformsVector3)
            gl->setVector3(uniform.first, uniform.second);
    }
}

void Material::unbind() {
    if (mShaderProgram) gl->unbindShaderProgram(0);
}