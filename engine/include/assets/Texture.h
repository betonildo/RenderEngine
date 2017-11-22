#ifndef TEXTURE_H
#define TEXTURE_H

#include "OSExport.h"
#include "assets/Asset.h"
#include "typedefs.h"
#include "graphics/TextureFormat.h"

class GraphicLibrary;

class ENGINE_API Texture : public Asset {

public:
    Texture();
    Texture(const Texture& other);
    ~Texture();

    void setData(byte* data, TextureFormat format);
    void active(uint textureIndex);
    void deactive(uint textureIndex);

private:
    uint mTextureLocation;
    GraphicLibrary* gl;
};

#endif /*TEXTURE_H*/
