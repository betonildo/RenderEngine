#ifndef RESOURCES_H
#define RESOURCES_H

#include "OSExport.h"

class Mesh;
class Texture;
class TextureLoader;
class MeshLoader;

class ENGINE_API Resources {

public:
    static void init();
    static Mesh loadMesh(const char* path);
    static Texture loadTexture(const char* path);

private:
    static TextureLoader* mTextureLoader;
    static MeshLoader* mMeshLoader;
};

#endif /*RESOURCES_H*/