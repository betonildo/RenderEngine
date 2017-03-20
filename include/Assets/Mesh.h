#include "Assets/Asset.h"

#ifndef MESH_H
#define MESH_H

template<class VertexType>
class Mesh : public Asset {

public:
    virtual void load(const char* relativePath) = 0;

protected:
    virtual void m_uploadToGPU();
    unsigned int m_meshID;
    std::vector<VertexType> m_vertices;
    std::vector<unsigned short> m_indexes;
};

#endif /*MESH_H*/