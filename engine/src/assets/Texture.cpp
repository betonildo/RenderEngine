#include "assets/Texture.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"

Texture::Texture() {
    gl = GraphicLibrarySingleton::getInstance();
    mTextureLocation = gl->generateTextureBuffer();
}

Texture::~Texture() {
    // TODO: unload texture buffer
}

void Texture::setData(Color4* data, uint width, uint height) {
    gl->bindTexture(mTextureLocation);
    gl->bindTextureData(data, width, height);
    gl->unbindTexture(mTextureLocation);
}

void Texture::active(uint textureIndex) {
    gl->activeTexture(textureIndex);
}

void Texture::deactive(uint textureIndex) {
    gl->deactiveTexture(textureIndex);
}
