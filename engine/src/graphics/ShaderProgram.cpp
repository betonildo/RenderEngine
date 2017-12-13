#include "graphics/ShaderProgram.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"

ShaderProgram::ShaderProgram(unsigned int shaderProgramLocation) {
    gl = GraphicLibrarySingleton::getInstance();
	mShaderProgramLocation = shaderProgramLocation;
}

void ShaderProgram::setUniform(unsigned int uniformLocation, Vector3 v) {
    gl->setVector3(uniformLocation, v);
}

void ShaderProgram::setUniform(unsigned int uniformLocation, Vector2 v) {
    gl->setVector2(uniformLocation, v);
}

void ShaderProgram::setUniform(unsigned int uniformLocation, Matrix4 m) {
    gl->setMatrix4(uniformLocation, m);
}

unsigned int ShaderProgram::getUniformLocation(const char* uniformName) {
    return gl->getUniformLocation(mShaderProgramLocation, uniformName);
}

unsigned int ShaderProgram::getAttributeLocation(const char* attributeName) {
    return gl->getAttributeLocation(mShaderProgramLocation, attributeName);
}

void ShaderProgram::bind() {
    gl->bindShaderProgram(mShaderProgramLocation);
}

void ShaderProgram::unbind() {
    gl->unbindShaderProgram(mShaderProgramLocation);
}