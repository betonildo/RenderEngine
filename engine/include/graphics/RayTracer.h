#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "graphics/GraphicLibrary.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "graphics/Rect.h"
#include <vector>

class RayTracer : public GraphicLibrary {

public:
	RayTracer();
	void setUniform3f(unsigned int uniformLocation, float* data);
	void setUniform2f(unsigned int uniformLocation, float* data);
	void setUniformMatrix4(unsigned int uniformLocation, float* data);
	unsigned int getUniformLocation(const std::string& uniformName);
	unsigned int getAttributeLocation(const std::string& attributeName);
	void enableAttribute(unsigned int attributeLocation);
	void setVertexFormat(VertexFormat vertexFormat);
	void disableAttribute(unsigned int attributeLocation);
	unsigned int createShaderProgram(Shader* shaderSource);
	unsigned int generateVertexBuffer();
	unsigned int generateElementBuffer();
	Buffer* getVertexBuffer(unsigned int bufferLocation);
	Buffer* getElementBuffer(unsigned int bufferLocation);
	ShaderProgram* getShaderProgram(unsigned int shaderProgramLocation);
	void bindShaderProgram(unsigned int shaderProgramLocation);
	void unbindShaderProgram(unsigned int shaderProgramLocation);
	void bindBuffer(unsigned int bufferLocation);
	void unbindBuffer(unsigned int bufferLocation);
	void enqueueCommand();
	void dequeueCommand();
	void drawElements(ElementFormat elementFormat);
	void processCommandList();
	void init();
	void setViewportRect(Rect rect);
	void* getBackBuffer();

private:
	std::vector< ShaderProgram > mShaderPrograms;
	std::vector< Buffer > mVertexBuffers;
	std::vector< Buffer > mIndexBuffers;

	unsigned int mShaderProgramsCount;
	unsigned int mVertexBuffersCount;
	unsigned int mIndexBuffersCount;

	Rect mRect;
	unsigned char* mBackBuffer;
};


#endif /*RAYTRACER_H*/
