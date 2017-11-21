#ifndef TEXTURE_H
#define TEXTURE_H

#include "OSExport.h"
#include "typedefs.h"

enum class TextureFormat;
class Color4;
class Vector2;
class GraphicLibrary;

class ENGINE_API Texture {

public:
    Texture();
    ~Texture();

    void setData(Color4* data, uint width, uint height);
    void active(uint textureIndex);
    void deactive(uint textureIndex);

private:
    uint mTextureLocation;
    GraphicLibrary* gl;
};

#endif /*TEXTURE_H*/
