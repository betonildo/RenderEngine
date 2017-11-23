#ifndef MESHLOADER_H
#define MESHLOADER_H

#include "OSExport.h"

class Mesh;

class ENGINE_API MeshLoader {

public:
    virtual Mesh load(const char* path) = 0;
};


#endif /*MESHLOADER_H*/