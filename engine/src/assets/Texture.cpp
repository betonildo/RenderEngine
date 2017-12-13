#include "assets/Texture.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"

Texture::Texture() {
    gl = GraphicLibrarySingleton::getInstance();
    mTextureLocation = gl->generateTextureBuffer();
}

Texture::Texture(const Texture& other) {
    mTextureLocation = other.mTextureLocation;
}

Texture::~Texture() {
    // TODO: unload texture buffer
}

void Texture::setData(byte* data, TextureFormat format) {
    gl->bindTexture(mTextureLocation);
    gl->bindTextureData(data, format);
    gl->unbindTexture(mTextureLocation);
}

void Texture::bind() {
    gl->bindTexture(mTextureLocation);
}

void Texture::unbind() {
    gl->unbindTexture(mTextureLocation);
}

void Texture::active(uint textureIndex) {
    gl->activeTexture(textureIndex);
}

void Texture::deactive(uint textureIndex) {
    gl->deactiveTexture(textureIndex);
}
