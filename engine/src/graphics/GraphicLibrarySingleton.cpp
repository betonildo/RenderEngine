#include "graphics/GraphicLibrarySingleton.h"

GraphicLibrary* mGlInstance;

void GraphicLibrarySingleton::setInstance(GraphicLibrary* gl) {
    mGlInstance = gl;
}

GraphicLibrary* GraphicLibrarySingleton::getInstance() {
    return mGlInstance;
}