#ifndef GRAPHICLIBRARY_H
#define GRAPHICLIBRARY_H

#include <string>
class Buffer;
class ShaderProgram;
class Shader;
class VertexFormat;
class ElementFormat;
class Rect;

class GraphicLibrary {

public:

    virtual void setUniform3f(unsigned int uniformLocation, float* data) = 0;
    virtual void setUniform2f(unsigned int uniformLocation, float* data) = 0;
    virtual void setUniformMatrix4(unsigned int uniformLocation, float* data) = 0;
    virtual unsigned int getUniformLocation(const std::string& uniformName) = 0;
    virtual unsigned int getAttributeLocation(const std::string& attributeName) = 0;
    virtual void enableAttribute(unsigned int attributeLocation) = 0;
    virtual void setVertexFormat(VertexFormat vertexFormat) = 0;
    virtual void disableAttribute(unsigned int attributeLocation) = 0;

    virtual unsigned int createShaderProgram(Shader* shaderSource) = 0;
    virtual unsigned int generateVertexBuffer() = 0;
    virtual unsigned int generateElementBuffer() = 0;

    virtual Buffer* getVertexBuffer(unsigned int bufferLocation) = 0;
	virtual Buffer* getElementBuffer(unsigned int bufferLocation) = 0;
    virtual ShaderProgram* getShaderProgram(unsigned int shaderProgramLocation) = 0;

    virtual void bindShaderProgram(unsigned int shaderProgramLocation) = 0;
    virtual void unbindShaderProgram(unsigned int shaderProgramLocation) = 0;

    virtual void bindBuffer(unsigned int bufferLocation) = 0;
    virtual void unbindBuffer(unsigned int bufferLocation) = 0;

	virtual void enqueueCommand() = 0;
	virtual void dequeueCommand() = 0;
	virtual void drawElements(ElementFormat elementFormat) = 0;
    virtual void processCommandList() = 0;

    virtual void init() = 0;	
    virtual void setViewportRect(Rect rect) = 0;
    virtual void* getBackBuffer() = 0;

};

#endif /*GRAPHICLIBRARY_H*/