#include "assets/Material.h"
#include "graphics/ShaderProgram.h"

Material::Material() {
    mMatrix4CacheValid = false;
    mVector3CacheValid = false;
    mVector2CacheValid = false;
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
        // unsigned int uniformLocation = mShaderProgram->getUniformLocation(name);
        // mUniformsVector3[uniformLocation] = v;
    }
}

void Material::setUniform(const std::string& name, Vector2 v) {
    if (mShaderProgram) {
        mVector2CacheValid = false;
        // unsigned int uniformLocation = mShaderProgram->getUniformLocation(name);
        // mUniformsVector2[uniformLocation] = v;
    }
}

void Material::setUniform(const std::string& name, Matrix4 m) {
    if (mShaderProgram) {
        mMatrix4CacheValid = false;
        // unsigned int uniformLocation = mShaderProgram->getUniformLocation(name);
        // mUniformsMatrix4[uniformLocation] = m;
    }
}

void Material::setShaderProgram(ShaderProgram* shaderProgram) {
	mShaderProgram = shaderProgram;
}

void Material::bind() {
    if (mShaderProgram) mShaderProgram->bind();

    // ONLY SET TO SHADER NEW VALUES
    if (!mMatrix4CacheValid) {
        mMatrix4CacheValid = true;
        for (auto uniform : mUniformsMatrix4)
            mShaderProgram->setUniform(uniform.first, uniform.second);
    }

    if (!mVector2CacheValid) {
        mVector2CacheValid = true;
        for (auto uniform : mUniformsVector2)
            mShaderProgram->setUniform(uniform.first, uniform.second);
    }

    if (!mVector3CacheValid) {
        mVector3CacheValid = true;
        for (auto uniform : mUniformsVector3)
            mShaderProgram->setUniform(uniform.first, uniform.second);
    }
}

void Material::unbind() {
    if (mShaderProgram) mShaderProgram->unbind();
}