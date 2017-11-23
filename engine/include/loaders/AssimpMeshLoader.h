#ifndef ASSIMPMESHLOADER_H
#define ASSIMPMESHLOADER_H

#include "loaders/MeshLoader.h"

class ENGINE_API AssimpMeshLoader : public MeshLoader {

public:
    virtual Mesh load(const char* path);
};


#endif /*ASSIMPMESHLOADER_H*/