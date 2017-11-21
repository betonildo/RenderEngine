#ifndef SOILTEXTURELOADER_H
#define SOILTEXTURELOADER_H

#include "loaders/TextureLoader.h"

class ENGINE_API SoilTextureLoader : public TextureLoader {

public:
    void load(const char* path, Color4** pixels, uint& width, uint& height);
};

#endif /*SOILTEXTURELOADER_H*/