#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include "OSExport.h"
#include "typedefs.h"

class TextureFormat;

class ENGINE_API TextureLoader {

public:
    virtual byte* load(const char* path, TextureFormat& format) = 0;
};

#endif /*TEXTURELOADER_H*/