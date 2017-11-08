#ifndef MESH_H
#define MESH_H

#include "OSExport.h"
#include "assets/Asset.h"
#include <vector>
class Vertex;

class ENGINE_API Mesh : public Asset {

public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};

#endif /*MESH_H*/