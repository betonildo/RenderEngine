#include "loaders/SoilTextureLoader.h"
#include "LinearMath.h"
#include "SOIL.h"

void SoilTextureLoader::load(const char* path, Color4** pixels, uint& width, uint& height) {

    int channels;
    byte *ht_map = SOIL_load_image(path, &width, &height, &channels, SOIL_LOAD_RGBA);
    pixels[0] = (Color4*)(ht_map);
}