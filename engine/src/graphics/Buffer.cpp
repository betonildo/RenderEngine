#include "graphics/Buffer.h"
#include "graphics/GraphicLibrary.h"
#include "graphics/GraphicLibrarySingleton.h"

Buffer::Buffer(unsigned int bufferLocation) {
    mBufferLocation = bufferLocation;
    gl = GraphicLibrarySingleton::getInstance();
}

void Buffer::attachData(void* data, unsigned int length) {
    mData = data;
    mDataLength = length;
}

void Buffer::setType(BufferType bufferType) {
    mBufferType = bufferType;
}

void Buffer::bind() {
    gl->bindBuffer(mBufferLocation);
}

void Buffer::unbind() {
    gl->unbindBuffer(mBufferLocation);
}