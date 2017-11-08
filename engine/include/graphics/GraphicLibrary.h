#ifndef GRAPHICLIBRARY_H
#define GRAPHICLIBRARY_H

#include <string>

class GraphicLibrary {

public:
    virtual void setUniform3f(unsigned int uniformLocation, float* data) = 0;
    virtual void setUniform2f(unsigned int uniformLocation, float* data) = 0;
    virtual void setUniformMatrix4(unsigned int uniformLocation, float* data) = 0;
    virtual unsigned int getUniformLocation(const std::string& uniformName) = 0;
    virtual unsigned int getAttributeLocation(const std::string& attributeName) = 0;

    virtual unsigned int generateArrayBuffer() = 0;
    virtual unsigned int generateElementBuffer() = 0;
    virtual unsigned int generaterMeshBuffer() = 0;

    virtual void bindShaderProgram(unsigned int shaderProgramLocation) = 0;
    virtual void unbindShaderProgram(unsigned int shaderProgramLocation) = 0;

    virtual void bindBuffer(unsigned int bufferLocation) = 0;
    virtual void unbindBuffer(unsigned int bufferLocation) = 0;
};

#endif /*GRAPHICLIBRARY_H*/