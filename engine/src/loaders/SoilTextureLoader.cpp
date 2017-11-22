#include "loaders/SoilTextureLoader.h"
#include "LinearMath.h"
#include "SOIL.h"

byte* SoilTextureLoader::load(const char* path, TextureFormat& format) {
    return SOIL_load_image(path, &format.width, &format.height, &format.channels, SOIL_LOAD_RGBA);
}