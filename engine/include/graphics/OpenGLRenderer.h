#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "graphics/GraphicLibrary.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "graphics/Rect.h"
#include "LinearMath.h"
#include <vector>
#include <queue>

class OpenGLRenderer : public GraphicLibrary {

public:
	OpenGLRenderer();

	void pushMaterial(const Material* material);
	void pushLights(const Light* lights, uint lightCount);
	void pushMatrix4(MatrixType type, const Matrix4& m);
	void pushAttributeValue(AttributeType type, const void* v, uint count);

	void setVector3(uint uniformLocation, const Vector3& v);
	void setVector2(uint uniformLocation, const Vector2& v);
	void setMatrix4(uint uniformLocation, const Matrix4& m);

	unsigned int getUniformLocation(const char* uniformName);
	unsigned int getAttributeLocation(const char* attributeName);
	void enableAttribute(unsigned int attributeLocation);
	void disableAttribute(unsigned int attributeLocation);
	unsigned int createShaderProgram(Shader* shaderSource);
	unsigned int generateVertexBuffer();
	unsigned int generateIndexBuffer();

	ShaderProgram* getShaderProgram(unsigned int shaderProgramLocation);
	void bindShaderProgram(unsigned int shaderProgramLocation);
	void unbindShaderProgram(unsigned int shaderProgramLocation);
	
	void bindVertexBuffer(uint bufferLocation);
	void bindVertexBufferData(VertexFormat vertexFormat, void* data, uint length);
	void unbindVertexBuffer(uint bufferLocation);

	void bindIndexBuffer(uint bufferLocation);
	void bindIndexBufferData(ElementFormat elementFormat, void* data, uint length);
	void unbindIndexBuffer(uint bufferLocation);

	void pushBackCommand();
	void clearCommandList();
	void drawElements();
	void processCommandList();
	void init();
	void setViewportRect(Rect rect);
	void* getBackBuffer();

private:
	struct IndexBuffer {
		void* data;
		uint length;
		ElementFormat format;
	};

	struct VertexBuffer {
		void* data;
		uint length;
		VertexFormat format;
	};
};