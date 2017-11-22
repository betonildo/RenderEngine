#include "assets/Resources.h"
#include "assets/Texture.h"
#include "assets/Mesh.h"
#include "loaders/TextureLoader.h"
#include "graphics/TextureFormat.h"

TextureLoader* Resources::mTextureLoader = nullptr;

void Resources::init() {
    
}

Mesh* Resources::loadMesh(const char* path) {
    return nullptr;
}

Texture Resources::loadTexture(const char* path) {
    Texture tex;
    TextureFormat format;
    byte* textureData = Resources::mTextureLoader->load(path, format);
    tex.setData(textureData, format);
    return tex;
}