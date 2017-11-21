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
	void setPositions(std::vector<Vector3>& positions);
	void setNormals(std::vector<Vector3>& normals);
	void setUV(std::vector<Vector2>& uvs);
	void setIndices(std::vector<unsigned int>& indices);
	void drawTriangles();

	inline static Mesh* createQuad() {
		auto quad = new Mesh();

		std::vector<Vector3> positions = {
			Vector3(-1,-1, 0),
			Vector3( 1,-1, 0),
			Vector3( 1, 1, 0),
			Vector3(-1, 1, 0)
		};

		std::vector<Vector3> normals = {
			Vector3( 0, 0, 1),
			Vector3( 0, 0, 1),
			Vector3( 0, 0, 1),
			Vector3( 0, 0, 1)
		};

		std::vector<Vector2> uvs = {
			Vector2( 0, 0),
			Vector2( 1, 0),
			Vector2( 1, 1),
			Vector2( 0, 1)
		};

		std::vector<unsigned int> indices = {
			0, 1, 2,
			0, 2, 3
		};

		quad->setPositions(positions);
		quad->setNormals(normals);
		quad->setUV(uvs);
		quad->setIndices(indices);

		return quad;
	}

	inline static Mesh* createBox() {
		auto box = new Mesh();
		
		std::vector<Vector3> positions = {
			Vector3(-1,-1, 1),
			Vector3( 1,-1, 1),
			Vector3( 1, 1, 1),
			Vector3(-1,-1, 1),
			Vector3(-1,-1,-1),
			Vector3( 1,-1,-1),
			Vector3( 1, 1,-1),
			Vector3(-1,-1,-1),
		};

		std::vector<Vector3> normals = {
			Vector3(-1,-1, 1),
			Vector3( 1,-1, 1),
			Vector3( 1, 1, 1),
			Vector3(-1,-1, 1),
			Vector3(-1,-1,-1),
			Vector3( 1,-1,-1),
			Vector3( 1, 1,-1),
			Vector3(-1,-1,-1),
		};

		std::vector<Vector2> uvs = {
			Vector2(0,0),
			Vector2(1,0),
			Vector2(1,1),
			Vector2(0,1),
			
			Vector2(0,1),
			Vector2(1,1),
			Vector2(1,0),
			Vector2(1,0)
		};

		std::vector<unsigned int> indices = {
			0, 1, 2,
			0, 2, 3,
			3, 2, 6,
			3, 6, 7,
			4, 0, 3,
			3, 4, 7,
			4, 5, 6,
			4, 5, 7,
			1, 0, 4,
			1, 4, 5,
			1, 5, 6,
			1, 6, 2
		};

		box->setPositions(positions);
		box->setNormals(normals);
		box->setUV(uvs);
		box->setIndices(indices);

		return box;
	}

private:
	unsigned int mPositionBuffer;
	unsigned int mNormalBuffer;
	unsigned int mUVBuffer;
	unsigned int mIndexBuffer;

	GraphicLibrary* gl;
};

#endif /*MESH_H*/