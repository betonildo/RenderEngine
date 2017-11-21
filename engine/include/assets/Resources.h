#ifndef RESOURCES_H
#define RESOURCES_H

#include "OSExport.h"

class Mesh;
class Texture;

class ENGINE_API Resources {

public:
    static Mesh* loadMesh(const char* path);
    static Texture* loadTexture(const char* path);
};

#endif /*RESOURCES_H*/