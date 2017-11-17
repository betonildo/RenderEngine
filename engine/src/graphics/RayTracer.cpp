#include "graphics/RayTracer.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "graphics/ShaderProgram.h"
#include <iostream>

using namespace std;

RayTracer::RayTracer() {
	mShaderProgramsCount = 0;
	mVertexBuffersCount = 0;
	mIndexBuffersCount = 0;
}

void RayTracer::pushMatrix4(MatrixType type, const Matrix4& m) {
	
	switch (type)
	{
	case GraphicLibrary::MatrixType::World:
		mCurrentCommand.World = m;
		break;
	case GraphicLibrary::MatrixType::View:
		mCurrentCommand.View = m;
		break;
	case GraphicLibrary::MatrixType::Projection:
		mCurrentCommand.Projection = m;
		break;
	default:
		break;
	}
}

void RayTracer::pushMaterial(const Material* material) {
	mCurrentCommand.material = material;
}

void RayTracer::pushLights(const Light* lights, uint lightCount) {
	mCurrentCommand.lights.lights = lights;
	mCurrentCommand.lights.lightCount = lightCount;
}

void RayTracer::pushAttributeValue(AttributeType type, const void* v, uint count) {
	switch (type)
	{
	case GraphicLibrary::AttributeType::Position:
		mCurrentCommand.positions.values.vectors3 = (const Vector3*)v;
		mCurrentCommand.positions.count = count;
		break;
	case GraphicLibrary::AttributeType::Normal:
		mCurrentCommand.normals.values.vectors3 = (const Vector3*)v;
		mCurrentCommand.normals.count = count;
		break;
	case GraphicLibrary::AttributeType::UV0:
		mCurrentCommand.uvs.values.vectors2 = (const Vector2*)v;
		mCurrentCommand.uvs.count = count;
		break;
	case GraphicLibrary::AttributeType::UV1:
		break;
	case GraphicLibrary::AttributeType::UV2:
		break;
	default:
		break;
	}
}

void RayTracer::setVector3(uint uniformLocation, const Vector3& v) {

}

void RayTracer::setVector2(uint uniformLocation, const Vector2& v) {

}

void RayTracer::setMatrix4(uint uniformLocation, const Matrix4& m) {

}

unsigned int RayTracer::getUniformLocation(const char* uniformName) {
	cout << "Getting uniform location '" << uniformName << "'" << endl;
	return 0;
}

unsigned int RayTracer::getAttributeLocation(const char* attributeName) {
	cout << "Getting attribute location '" << attributeName << "'" << endl;
	return 0;
}

void RayTracer::enableAttribute(unsigned int attributeLocation) {
	cout << "Enabling attribute " << attributeLocation << endl;
	VertexBuffer* buffer = &mVertexBuffers[attributeLocation];
	pushAttributeValue(buffer->format.type, buffer->data, buffer->length);
}

void RayTracer::disableAttribute(unsigned int attributeLocation) {
	cout << "Disabling attribute " << attributeLocation << endl;
}

unsigned int RayTracer::createShaderProgram(Shader* shaderSource) {
	cout << "Creating a shader from source " << shaderSource << endl;
	unsigned int shaderProgramLocation = mShaderProgramsCount;
	mShaderPrograms.emplace_back(shaderProgramLocation);
	mShaderProgramsCount++;
	return shaderProgramLocation;
}

unsigned int RayTracer::generateVertexBuffer() {
	cout << "Generating array buffer" << endl;
	unsigned int bufferLocation = mVertexBuffersCount;
	mVertexBuffers.emplace_back();
	mVertexBuffers[bufferLocation] = {};
	mVertexBuffersCount++;
	return bufferLocation;
}

unsigned int RayTracer::generateIndexBuffer() {
	cout << "Generating element buffer" << endl;
	unsigned int bufferLocation = mIndexBuffersCount;
	mIndexBuffers.emplace_back();
	mIndexBuffers[bufferLocation] = {};
	mIndexBuffersCount++;
	return bufferLocation;
}

ShaderProgram* RayTracer::getShaderProgram(unsigned int shaderProgramLocation) {
	cout << "Getting ShaderProgram pointer" << endl;
	return &mShaderPrograms[shaderProgramLocation];
}

void RayTracer::bindShaderProgram(unsigned int shaderProgramLocation) {
	cout << "Binding ShaderProgram " << shaderProgramLocation  << endl;
}

void RayTracer::unbindShaderProgram(unsigned int shaderProgramLocation) {
	cout << "Unbinding ShaderProgram " << shaderProgramLocation << endl;
}

void RayTracer::bindVertexBuffer(uint bufferLocation) {
	mCurrentVertexBuffer = &mVertexBuffers[bufferLocation];
}

void RayTracer::bindVertexBufferData(VertexFormat vertexFormat, void* data, uint length) {
	unsigned int elementSize = VertexFormat::AttributeByteSizes(vertexFormat.attributeType);
	mCurrentVertexBuffer->data = calloc(length, elementSize);
	memcpy(mCurrentVertexBuffer->data, data, elementSize * length);
	mCurrentVertexBuffer->length = length;
	mCurrentVertexBuffer->format = vertexFormat;
}

void RayTracer::unbindVertexBuffer(uint bufferLocation) {
	mCurrentVertexBuffer = nullptr;
}

void RayTracer::bindIndexBuffer(uint bufferLocation) {
	mCurrentIndexBuffer = &mIndexBuffers[bufferLocation];
}

void RayTracer::bindIndexBufferData(ElementFormat elementFormat, void* data, uint length) {
	unsigned int elementSize = ElementFormat::IndexTypeSizes(elementFormat.type);
	mCurrentIndexBuffer->data = calloc(length, elementSize);
	memcpy(mCurrentIndexBuffer->data, data, elementSize * length);
	mCurrentIndexBuffer->length = length;
	mCurrentIndexBuffer->format = elementFormat;
}

void RayTracer::unbindIndexBuffer(uint bufferLocation) {
	mCurrentIndexBuffer = nullptr;
}

void RayTracer::pushBackCommand() {
	cout << "pushBackCommand" << endl;
	bzero(&mCurrentCommand, sizeof(Command));
}

void RayTracer::clearCommandList() {
	// cout << "clearCommandList" << endl;
	mCommandList.clear();
}

void RayTracer::drawElements() {
	cout << "Draw elements with element format" << endl;
	mCommandList.push_back(mCurrentCommand);
}

void RayTracer::processCommandList() {
	// cout << "Process all commands" << endl;

	unsigned int blobSize = mBackBuffer.size();
	byte* blobData = mBackBuffer.data();

	for (unsigned int i = 0; i < mRect.height * 4; i++) {
		for (unsigned int j = 0; j < mRect.width; j += 4) {
			blobData[i * mRect.width + j + 0] = 255;
			blobData[i * mRect.width + j + 1] = 0;
			blobData[i * mRect.width + j + 2] = 0;
			blobData[i * mRect.width + j + 3] = 255;
		}
	}
}

void RayTracer::init() {
	cout << "Init RayTracer" << endl;
}

void RayTracer::setViewportRect(Rect rect) {
	cout << "Setup Viewport {" << rect.x << ", " << rect.y << ", " << rect.width << ", " << rect.height << "}" << endl;
	mRect = rect;
	mBackBuffer.resize(rect.width * rect.height * 4);
}

void* RayTracer::getBackBuffer() {
	return mBackBuffer.data();
}
