#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "graphics/GraphicLibrary.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "graphics/PixelColor.h"
#include "graphics/library/OpenGL/VertexBuffer.h"
#include "graphics/library/OpenGL/IndexBuffer.h"
#include "graphics/Rect.h"
#include "LinearMath.h"
#include <vector>
#include <queue>


class OpenGLRenderer : public GraphicLibrary {

public:
	OpenGLRenderer();

	void pushMaterial(const Material* material);
	void pushLights(const Light* lights, uint lightCount);
	void pushCamera(const Camera* camera);
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

	uint generateTextureBuffer();
	void bindTexture(uint textureLocation);
    void bindTextureData(byte* data, TextureFormat format);
    void unbindTexture(uint textureLocation);
	void activeTexture(uint textureIndex);
	void deactiveTexture(uint textureIndex);

	ShaderProgram* getShaderProgram(unsigned int shaderProgramLocation);
	void bindShaderProgram(unsigned int shaderProgramLocation);
	void unbindShaderProgram(unsigned int shaderProgramLocation);
	
	void bindVertexBuffer(uint bufferLocation);
	void bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector3> data);
	void bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector2> data);
	void bindVertexBufferData(VertexFormat vertexFormat, void* data, uint length);
	void unbindVertexBuffer(uint bufferLocation);

	void bindIndexBuffer(uint bufferLocation);
	void bindIndexBufferData(ElementFormat elementFormat, std::vector<unsigned int> data);
	void unbindIndexBuffer(uint bufferLocation);

	void pushBackObject();
	void clearObjectList();
	void drawElements();
	void processObjectList();
	void init();
	void setViewportRect(Rect rect);
	void* getBackBuffer();

private:

	static const uint kMaxLights = 10;

	const Light* mCurrentLights;
	uint mCurrentLightsCount;
	
	const Camera* mCurrentCamera;

	struct Object {
		Material* material;
		uint shader;
		VertexBuffer* vertexbuffers[10];
		uint vertexbufferCount = 0;
		// TODO: have in mind, to future handle 
		//		 multiple index buffers to draw
		//		 different parts of a model.
		IndexBuffer* indexbuffer;
		Matrix4 world;
	};

	Object mCurrentBoundObject;
	VertexBuffer* mCurrentBoundVertexBuffer;
	IndexBuffer* mCurrentBoundIndexBuffer;

	std::vector<VertexBuffer> mVertexBuffers;
	std::vector<IndexBuffer> mIndexBuffers;
	std::vector<Object> mCurrentObjectsList;
	std::vector<PixelColor> mBackBufferData;

	std::vector<ShaderProgram> mShaderPrograms;

	Rect mViewport;

	Matrix4 mMatrixCache[(uint)MatrixType::Count];

	static uint ElementDrawModeToOpenGLMode(const ElementFormat& format);
};

#endif // OPENGLRENDERER_H