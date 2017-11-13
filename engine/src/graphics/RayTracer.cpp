#include "graphics/RayTracer.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "graphics/Buffer.h"
#include "graphics/ShaderProgram.h"
#include "LinearMath.h"
#include <iostream>

using namespace std;

RayTracer::RayTracer() {
	mShaderProgramsCount = 0;
	mVertexBuffersCount = 0;
	mIndexBuffersCount = 0;
}

void RayTracer::setUniform3f(unsigned int uniformLocation, float* data) {
	cout << "Setting uniform 3f" << uniformLocation << "[" << data[0] << " " << data[1] << " " << data[2] << "]" << endl;
}

void RayTracer::setUniform2f(unsigned int uniformLocation, float* data) {
	cout << "Setting uniform 2f" << uniformLocation << "[" << data[0] << " " << data[1] << "]" << endl;
}

void RayTracer::setUniformMatrix4(unsigned int uniformLocation, float* data) {
	cout << "Setting uniform matrix4 f" << uniformLocation << "[" << data[0] << " " << data[1] << " " << data[2] << " ... " << data[15] << "]" << endl;
}

unsigned int RayTracer::getUniformLocation(const std::string& uniformName) {
	cout << "Getting uniform location '" << uniformName << "'" << endl;
	return 0;
}

unsigned int RayTracer::getAttributeLocation(const std::string& attributeName) {
	cout << "Getting attribute location '" << attributeName << "'" << endl;
	return 0;
}

void RayTracer::enableAttribute(unsigned int attributeLocation) {
	cout << "Enabling attribute " << attributeLocation << endl;
}

void RayTracer::setVertexFormat(VertexFormat vertexFormat) {
	cout << "Setting vertex format " << endl;
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
	mVertexBuffers.emplace_back(bufferLocation);
	mVertexBuffersCount++;
	return bufferLocation;
}

unsigned int RayTracer::generateElementBuffer() {
	cout << "Generating element buffer" << endl;
	unsigned int bufferLocation = mIndexBuffersCount;
	mIndexBuffers.emplace_back(bufferLocation);
	mIndexBuffersCount++;
	return bufferLocation;
}

Buffer* RayTracer::getVertexBuffer(unsigned int bufferLocation) {
	cout << "Getting vertex buffer pointer" << endl;
	return &mVertexBuffers[bufferLocation];
}

Buffer* RayTracer::getElementBuffer(unsigned int bufferLocation) {
	cout << "Getting element buffer pointer" << endl;
	return &mIndexBuffers[bufferLocation];
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

void RayTracer::bindBuffer(unsigned int bufferLocation) {
	cout << "Binding bindBuffer " << bufferLocation << endl;
}

void RayTracer::unbindBuffer(unsigned int bufferLocation) {
	cout << "Unbinding bindBuffer " << bufferLocation << endl;
}

void RayTracer::enqueueCommand() {
	cout << "Enqueue command" << endl;
}

void RayTracer::dequeueCommand() {
	cout << "Dequeue command" << endl;
}

void RayTracer::drawElements(ElementFormat elementFormat) {
	cout << "Draw elements with element format" << endl;
}

void RayTracer::processCommandList() {
	// cout << "Process all commands" << endl;
}

void RayTracer::init() {
	cout << "Init RayTracer" << endl;
}

void RayTracer::setViewportRect(Rect rect) {
	cout << "Setup Viewport {" << rect.x << ", " << rect.y << ", " << rect.width << ", " << rect.height << "}" << endl;
	mRect = rect;
}

void* RayTracer::getBackBuffer() {
	typedef unsigned char byte;
	static byte* screenTest;
	if (!screenTest) {
		unsigned int width = 640;
		unsigned int height = 480;
		unsigned int pixelComponents = 4;

		unsigned int blobSize = width * height * pixelComponents;
		screenTest = new byte[blobSize];

		for (unsigned int i = 0; i < height * 4;i++) {
			for (unsigned int j = 0; j < width; j+=4) {
				screenTest[i * width + j + 0] = 255;
				screenTest[i * width + j + 1] = 0;
				screenTest[i * width + j + 2] = 0;
				screenTest[i * width + j + 3] = 255;
			}

			if (i == height - 1) cout << i << endl;
		}

		// for (unsigned int i = 0; i < blobSize; i++) {
		// 	screenTest[i] = 255;
		// }
	}

	return screenTest;
}