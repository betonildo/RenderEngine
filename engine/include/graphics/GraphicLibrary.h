#ifndef GRAPHICLIBRARY_H
#define GRAPHICLIBRARY_H

#include <vector>
#include "LinearMath.h"
#include "typedefs.h"

class Material;
class Buffer;
class ShaderProgram;
class Shader;
struct TextureFormat;
struct VertexFormat;
struct ElementFormat;
struct Rect;
class Light;
class Camera;

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
	virtual void pushCamera(const Camera* camera) = 0;
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

	virtual uint generateTextureBuffer() = 0;
	virtual void bindTexture(uint textureLocation) = 0;
    virtual void bindTextureData(byte* data, TextureFormat format) = 0;
    virtual void unbindTexture(uint textureLocation) = 0;
	virtual void activeTexture(uint textureIndex) = 0;
	virtual void deactiveTexture(uint textureIndex) = 0;
	
	virtual ShaderProgram* getShaderProgram(uint shaderProgramLocation) = 0;

    virtual void bindShaderProgram(uint shaderProgramLocation) = 0;
    virtual void unbindShaderProgram(uint shaderProgramLocation) = 0;

	virtual void bindVertexBuffer(uint bufferLocation) = 0;
	virtual void bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector3> data) = 0;
	virtual void bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector2> data) = 0;
	virtual void unbindVertexBuffer(uint bufferLocation) = 0;

    virtual void bindIndexBuffer(uint bufferLocation) = 0;
	virtual void bindIndexBufferData(ElementFormat elementFormat, std::vector<unsigned int> data) = 0;
    virtual void unbindIndexBuffer(uint bufferLocation) = 0;

	virtual void pushBackObject() = 0;
    virtual void clearObjectList() = 0;
	virtual void drawElements() = 0;
    virtual void processObjectList() = 0;

    virtual void init() = 0;	
    virtual void setViewportRect(Rect rect) = 0;
    virtual void* getBackBuffer() = 0;

};

#endif /*GRAPHICLIBRARY_H*/