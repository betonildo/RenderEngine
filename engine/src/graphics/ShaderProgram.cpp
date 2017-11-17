#include "graphics/ShaderProgram.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"

ShaderProgram::ShaderProgram(unsigned int shaderProgramLocation) {
    gl = GraphicLibrarySingleton::getInstance();
	mShaderProgramLocation = shaderProgramLocation;
}

void ShaderProgram::setUniform(unsigned int uniformLocation, Vector3 v) {
    
}

void ShaderProgram::setUniform(unsigned int uniformLocation, Vector2 v) {

}

void ShaderProgram::setUniform(unsigned int uniformLocation, Matrix4 m) {

}

unsigned int ShaderProgram::getUniformLocation(const char* uniformName) {
    return gl->getUniformLocation(uniformName);
}

unsigned int ShaderProgram::getAttributeLocation(const char* attributeName) {
    return gl->getAttributeLocation(attributeName);
}

void ShaderProgram::bind() {
    gl->bindShaderProgram(mShaderProgramLocation);
}

void ShaderProgram::unbind() {
    gl->unbindShaderProgram(mShaderProgramLocation);
}