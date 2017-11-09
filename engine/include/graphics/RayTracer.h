#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "graphics/GraphicLibrary.h"

class RayTracer : public GraphicLibrary {

public:
    void setUniform3f(unsigned int uniformLocation, float* data);
    void setUniform2f(unsigned int uniformLocation, float* data);
    void setUniformMatrix4(unsigned int uniformLocation, float* data);
    unsigned int getUniformLocation(const std::string& uniformName);
    unsigned int getAttributeLocation(const std::string& attributeName);
    unsigned int generateArrayBuffer();
    unsigned int generateElementBuffer();
    unsigned int generaterMeshBuffer();
    void bindShaderProgram(unsigned int shaderProgramLocation);
    void unbindShaderProgram(unsigned int shaderProgramLocation);
    void bindBuffer(unsigned int bufferLocation);
    void unbindBuffer(unsigned int bufferLocation);
    void drawTriangles();
    void processCommandList();
};


#endif /*RAYTRACER_H*/