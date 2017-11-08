#include "graphics/Buffer.h"

Buffer::Buffer(unsigned int bufferLocation) {
    mBufferLocation = bufferLocation;
}

void Buffer::attachData(void* data, unsigned int length) {
    mData = data;
    mDataLength = length;
}

void Buffer::setType(BufferType bufferType) {
    mBufferType = bufferType;
}

void Buffer::bind() {

}

void Buffer::unbind() {

}