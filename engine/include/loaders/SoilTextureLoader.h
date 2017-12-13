#ifndef SOILTEXTURELOADER_H
#define SOILTEXTURELOADER_H

#include "loaders/TextureLoader.h"

class ENGINE_API SoilTextureLoader : public TextureLoader {

public:
    SoilTextureLoader();
    byte* load(const char* path, TextureFormat& format);
};

#endif /*SOILTEXTURELOADER_H*/