#include "graphics/ShaderProgram.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"

ShaderProgram::ShaderProgram(unsigned int shaderProgramLocation) {
    gl = GraphicLibrarySingleton::getInstance();
	mShaderProgramLocation = shaderProgramLocation;
}

void ShaderProgram::setUniform(unsigned int uniformLocation, Vector3 v) {
    gl->setUniform3f(uniformLocation, Math::value_ptr(v));
}

void ShaderProgram::setUniform(unsigned int uniformLocation, Vector2 v) {
    gl->setUniform2f(uniformLocation, Math::value_ptr(v));
}

void ShaderProgram::setUniform(unsigned int uniformLocation, Matrix4 m) {
    gl->setUniformMatrix4(uniformLocation, Math::value_ptr(m));
}

unsigned int ShaderProgram::getUniformLocation(const std::string& uniformName) {
    return gl->getUniformLocation(uniformName);
}

unsigned int ShaderProgram::getAttributeLocation(const std::string& attributeName) {
    return gl->getAttributeLocation(attributeName);
}

void ShaderProgram::bind() {
    gl->bindShaderProgram(mShaderProgramLocation);
}

void ShaderProgram::unbind() {
    gl->unbindShaderProgram(mShaderProgramLocation);
}