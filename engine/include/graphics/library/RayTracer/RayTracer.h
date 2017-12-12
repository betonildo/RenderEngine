#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "graphics/library/RayTracer/RayTracerAttributes.h"
#include "graphics/GraphicLibrary.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "graphics/Rect.h"
#include "graphics/library/RayTracer/Object.h"
#include "graphics/library/RayTracer/RaycastHit.h"
#include <vector>


class RayTracer : public GraphicLibrary {

public:
	RayTracer();

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

	LightsConfig mLights;
	const Camera* mCamera;

	std::vector<Object> mObjectsList;

	Object mCurrentObject;
	TextureBuffer* mCurrentTextureBuffer;
	IndexBuffer* mCurrentIndexBuffer;
	VertexBuffer* mCurrentVertexBuffer;

	std::vector< ShaderProgram > mShaderPrograms;
	std::vector< IndexBuffer > mIndexBuffers;
	std::vector< VertexBuffer > mVertexBuffers;
	std::vector< TextureBuffer > mTextureBuffers;

	uint mShaderProgramsCount;
	uint mVertexBuffersCount;
	uint mIndexBuffersCount;
	uint mTextureBuffersCount;

	Matrix4 mMatrixCache[(uint)MatrixType::Count];

	Rect mRect;
	
	std::vector<PixelColor> mBackBuffer;

	Ray ComputeCameraRay(const Vector3& cam_pos, const Vector3& cam_dir, const Vector3& cam_up, const Vector3& cam_right, int i, int j);
	PixelColor castRay(const Ray& ray, uint bounces);
	bool rayCastHit(const Ray& ray, RaycastHit& hit);
	Color4 calculatePointColor(const Ray& ray, const RaycastHit& hit);
	float Diffuse(const Vector3& N, const Vector3& L);
	float Specular(const Vector3& N, const Vector3& L, const Vector3& E, const float shininess);
	Color Phong(const Light* light, float diffuse, float specular, Color diffuseColor, Color specularColor);

	Color4 sampleTextureLinear(const TextureBuffer* textureBuffer, const Vector2& st);
};


#endif /*RAYTRACER_H*/
