#ifndef MESH_H
#define MESH_H

#include "OSExport.h"
#include "assets/Asset.h"
#include "LinearMath.h"
#include <vector>

class GraphicLibrary;

class ENGINE_API Mesh : public Asset {

public:
	Mesh();
	Mesh(const Mesh& other);
	void setPositions(std::vector<Vector3>& positions);
	void setNormals(std::vector<Vector3>& normals);
	void setUV(std::vector<Vector2>& uvs);
	void setIndices(std::vector<unsigned int>& indices);
	void drawTriangles();


private:
	unsigned int mPositionBuffer;
	unsigned int mNormalBuffer;
	unsigned int mUVBuffer;
	unsigned int mIndexBuffer;

	GraphicLibrary* gl;
};

#endif /*MESH_H*/