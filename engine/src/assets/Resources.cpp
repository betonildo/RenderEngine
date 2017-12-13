#include "assets/Resources.h"
#include "assets/Texture.h"
#include "assets/Mesh.h"
#include "loaders/TextureLoader.h"
#include "loaders/SoilTextureLoader.h"
#include "loaders/MeshLoader.h"
#include "loaders/AssimpMeshLoader.h"
#include "graphics/TextureFormat.h"
#include <vector>

TextureLoader* Resources::mTextureLoader = nullptr;
MeshLoader* Resources::mMeshLoader = nullptr;

void Resources::init() {
    mTextureLoader = new SoilTextureLoader();
    mMeshLoader = new AssimpMeshLoader();
}

Mesh Resources::loadMesh(const char* path) {
    return mMeshLoader->load(path);
}

Texture Resources::loadTexture(const char* path) {
    Texture tex;
    TextureFormat format;
    byte* textureData = Resources::mTextureLoader->load(path, format);
    tex.setData(textureData, format);
    return tex;
}