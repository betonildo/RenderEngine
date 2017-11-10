#ifndef MESH_H
#define MESH_H

#include "OSExport.h"
#include "assets/Asset.h"
#include <vector>

class Vertex;
class Buffer;

class ENGINE_API Mesh : public Asset {

public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

	void setPositionBuffer(Buffer* buffer);
	void setNormalBuffer(Buffer* buffer);
	void setUVBuffer(Buffer* buffer);
	void setIndexBuffer(Buffer* buffer);

	void bind();
	void unbind();

	void drawTriangles();

private:
	Buffer* mPositionBuffer;
	Buffer* mNormalBuffer;
	Buffer* mUVBuffer;
	Buffer* mIndexBuffer;
};

#endif /*MESH_H*/