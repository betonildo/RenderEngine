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

void Buffer::bind() {
    gl->bindBuffer(mBufferLocation);
    // TODO: SETUP VERTEX FORMAT IF BUFFER IS VERTEX BUFFER
}

void Buffer::unbind() {
    gl->unbindBuffer(mBufferLocation);
}