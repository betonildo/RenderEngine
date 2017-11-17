#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "OSExport.h"
#include "LinearMath.h"

class GraphicLibrary;

class ENGINE_API ShaderProgram {

public:
	ShaderProgram() = delete;
    explicit ShaderProgram(unsigned int shaderProgramLocation);

    void setUniform(unsigned int uniformLocation, Vector3 v);
    void setUniform(unsigned int uniformLocation, Vector2 v);
    void setUniform(unsigned int uniformLocation, Matrix4 m);

    unsigned int getUniformLocation(const char* uniformName);
    unsigned int getAttributeLocation(const char* attributeName);

    void bind();
    void unbind();

private:
    GraphicLibrary* gl;
    unsigned int mShaderProgramLocation;
};

#endif /*SHADERPROGRAM_H*/