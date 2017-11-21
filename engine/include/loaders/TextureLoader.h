#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include "OSExport.h"
#include "typedefs.h"

class Color4;

class ENGINE_API TextureLoader {

public:
    virtual void load(const char* path, Color4** pixels, uint& width, uint& height) = 0;
};

#endif /*TEXTURELOADER_H*/