#include "graphics/Buffer.h"
#include "graphics/GraphicLibrary.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/ElementFormat.h"
#include "graphics/VertexFormat.h"

Buffer::Buffer(unsigned int bufferLocation) {
    mBufferLocation = bufferLocation;
    gl = GraphicLibrarySingleton::getInstance();
}

void Buffer::attachData(void* data, unsigned int length) {
    mData = data;
    mDataLength = length;
}

void Buffer::bind() {
	gl->enableAttribute(mVertexFormat.attributeLocation);
    gl->bindBuffer(mBufferLocation);
	gl->setVertexFormat(mVertexFormat);
}

void Buffer::unbind() {
    gl->unbindBuffer(mBufferLocation);
	gl->disableAttribute(mVertexFormat.attributeLocation);
}

void Buffer::setVertexFormat(VertexFormat vertexFormat) {
	mVertexFormat = vertexFormat;
}

void Buffer::setElementFormat(ElementFormat elementFormat) {
	mElementFormat = elementFormat;
}

void Buffer::drawElements() {
	gl->drawElements(mElementFormat);
}