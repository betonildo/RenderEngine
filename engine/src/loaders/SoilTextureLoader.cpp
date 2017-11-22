#include "loaders/SoilTextureLoader.h"
#include "graphics/TextureFormat.h"
#include "SOIL.h"

SoilTextureLoader::SoilTextureLoader() {

}

byte* SoilTextureLoader::load(const char* path, TextureFormat& format) {
    return SOIL_load_image(path, &format.width, &format.height, &format.channels, SOIL_LOAD_RGBA);
}