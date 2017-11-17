#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "graphics/GraphicLibrary.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "graphics/Rect.h"
#include "LinearMath.h"
#include <vector>
#include <queue>

class RayTracer : public GraphicLibrary {

public:
	RayTracer();

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

	union AttributeUnion {
		const Vector3* vectors3;
		const Vector2* vectors2;
	};

	struct AttributeConfig {
		AttributeUnion values;
		uint count;
	};

	struct LightsConfig {
		const Light* lights;
		uint lightCount;
	};

	struct IndicesConfig {
		const uint* indices;
		uint indicesCount;
	};

	struct Command {
		LightsConfig lights;
		const Material* material;
		AttributeConfig positions;
		AttributeConfig normals;
		AttributeConfig uvs;
		IndicesConfig indices;
		ElementFormat format;
		Matrix4 World, View, Projection;
	};

	std::vector<Command> mCommandList;

	Command mCurrentCommand;
	IndexBuffer* mCurrentIndexBuffer;
	VertexBuffer* mCurrentVertexBuffer;

	typedef unsigned char byte;

	std::vector< ShaderProgram > mShaderPrograms;
	std::vector< IndexBuffer > mIndexBuffers;
	std::vector< VertexBuffer > mVertexBuffers;

	unsigned int mShaderProgramsCount;
	unsigned int mVertexBuffersCount;
	unsigned int mIndexBuffersCount;

	Rect mRect;
	std::vector<byte> mBackBuffer;

	//Matrix4 mMatrixCache[(uint)MatrixType::Count];
};


#endif /*RAYTRACER_H*/
