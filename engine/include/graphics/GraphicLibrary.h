#ifndef GRAPHICLIBRARY_H
#define GRAPHICLIBRARY_H

#include "LinearMath.h"

class Material;
class Buffer;
class ShaderProgram;
class Shader;
class VertexFormat;
class ElementFormat;
class Rect;
class Light;

typedef unsigned int uint;

class GraphicLibrary {

public:

	enum class MatrixType {
		World, WorldInverse, WorldTranspose, WorldInverseTranspose,
		View, ViewInverse, ViewTranspose, ViewInverseTranspose,
		Projection, ProjectionInverse, ProjectionTranspose, ProjectionInverseTranspose,
		WorldView, WorldViewInverse, WorldViewTranspose, WorldViewInverseTranspose,
		WorldViewProjection, WorldViewProjectionInverse, WorldViewProjectionTranspose, WorldViewProjectionInverseTranspose,
		Count
	};

	enum class AttributeType {
		Position, Normal, UV0, UV1, UV2,

		Count
	};
	
	virtual void pushMaterial(const Material* material) = 0;
	virtual void pushLights(const Light* lights, uint lightCount) = 0;
	virtual void pushMatrix4(MatrixType type, const Matrix4& m) = 0;
	virtual void pushAttributeValue(AttributeType type, const void* v, uint count) = 0;
	
	virtual void setVector3(uint uniformLocation, const Vector3& v) = 0;
	virtual void setVector2(uint uniformLocation, const Vector2& v) = 0;
	virtual void setMatrix4(uint uniformLocation, const Matrix4& m) = 0;

	virtual uint getUniformLocation(const char* uniformName) = 0;
    virtual uint getAttributeLocation(const char* attributeName) = 0;
    virtual void enableAttribute(uint attributeLocation) = 0;
    virtual void disableAttribute(uint attributeLocation) = 0;

    virtual uint createShaderProgram(Shader* shaderSource) = 0;
    virtual uint generateVertexBuffer() = 0;
    virtual uint generateIndexBuffer() = 0;
	
	virtual ShaderProgram* getShaderProgram(uint shaderProgramLocation) = 0;

    virtual void bindShaderProgram(uint shaderProgramLocation) = 0;
    virtual void unbindShaderProgram(uint shaderProgramLocation) = 0;

	virtual void bindVertexBuffer(uint bufferLocation) = 0;
	virtual void bindVertexBufferData(VertexFormat vertexFormat, void* data, uint length) = 0;
	virtual void unbindVertexBuffer(uint bufferLocation) = 0;

    virtual void bindIndexBuffer(uint bufferLocation) = 0;
	virtual void bindIndexBufferData(ElementFormat elementFormat, void* data, uint length) = 0;
    virtual void unbindIndexBuffer(uint bufferLocation) = 0;

	virtual void pushBackCommand() = 0;
    virtual void clearCommandList() = 0;
	virtual void drawElements() = 0;
    virtual void processCommandList() = 0;

    virtual void init() = 0;	
    virtual void setViewportRect(Rect rect) = 0;
    virtual void* getBackBuffer() = 0;

};

#endif /*GRAPHICLIBRARY_H*/