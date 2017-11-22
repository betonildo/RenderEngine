#ifndef RESOURCES_H
#define RESOURCES_H

#include "OSExport.h"

class Mesh;
class Texture;
class TextureLoader;

class ENGINE_API Resources {

public:
    template<typename TextureLoaderClass>
    inline static void setTextureLoaderInstance() {
        mTextureLoader = new TextureLoaderClass();
    }

    static void init();
    static Mesh* loadMesh(const char* path);
    static Texture loadTexture(const char* path);

private:
    static TextureLoader* mTextureLoader;
};

#endif /*RESOURCES_H*/