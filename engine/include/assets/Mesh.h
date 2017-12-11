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

	inline static Mesh* createSphere() {
		float radius = 1.0f;
		// Longitude |||
		int nbLong = 24;
		// Latitude ---
		int nbLat = 16;
		uint numOfVertices = (nbLong+1) * nbLat + 2;
		//#region Vertices
		Vector3* vertices = new Vector3[numOfVertices];
		float _pi = Math::pi<float>();//Mathf.PI;
		float _2pi = _pi * 2.0f;
		
		vertices[0] = Vector3(0, 1, 0) * radius;
		for( int lat = 0; lat < nbLat; lat++ )
		{
			float a1 = _pi * (float)(lat+1) / (nbLat+1);
			float sin1 = sinf(a1);
			float cos1 = cosf(a1);
		
			for( int lon = 0; lon <= nbLong; lon++ )
			{
				float a2 = _2pi * (float)(lon == nbLong ? 0 : lon) / nbLong;
				float sin2 = sinf(a2);
				float cos2 = cosf(a2);
		
				vertices[ lon + lat * (nbLong + 1) + 1] = Vector3( sin1 * cos2, cos1, sin1 * sin2 ) * radius;
			}
		}
		vertices[numOfVertices-1] = Vector3(0, 1, 0) * -radius;
		//#endregion
		
		//#region Normales		
		Vector3* normales = new Vector3[numOfVertices];
		for( int n = 0; n < numOfVertices; n++ )
			normales[n] = Math::normalize(vertices[n]);
		//#endregion
		
		//#region UVs
		Vector2* uvs = new Vector2[numOfVertices];
		uvs[0] = Vector2(0, 1);
		uvs[numOfVertices-1] = Vector2(0, 0);
		for( int lat = 0; lat < nbLat; lat++ )
			for( int lon = 0; lon <= nbLong; lon++ )
				uvs[lon + lat * (nbLong + 1) + 1] = Vector2( (float)lon / nbLong, 1.0f - (float)(lat+1) / (nbLat+1) );
		//#endregion
		
		//#region Triangles
		int nbFaces = numOfVertices;
		int nbTriangles = nbFaces * 2;
		int nbIndexes = nbTriangles * 3;
		int* triangles = new int[ nbIndexes ];
		
		//Top Cap
		int i = 0;
		for( int lon = 0; lon < nbLong; lon++ )
		{
			triangles[i++] = lon+2;
			triangles[i++] = lon+1;
			triangles[i++] = 0;
		}
		
		//Middle
		for( int lat = 0; lat < nbLat - 1; lat++ )
		{
			for( int lon = 0; lon < nbLong; lon++ )
			{
				int current = lon + lat * (nbLong + 1) + 1;
				int next = current + nbLong + 1;
		
				triangles[i++] = current;
				triangles[i++] = current + 1;
				triangles[i++] = next + 1;
		
				triangles[i++] = current;
				triangles[i++] = next + 1;
				triangles[i++] = next;
			}
		}
		
		//Bottom Cap
		for( int lon = 0; lon < nbLong; lon++ )
		{
			triangles[i++] = numOfVertices - 1;
			triangles[i++] = numOfVertices - (lon+2) - 1;
			triangles[i++] = numOfVertices - (lon+1) - 1;
		}
		//#endregion

		Mesh* m = new Mesh();
		std::vector<Vector3> positionsv;
		std::vector<Vector3> normalsv;
		std::vector<Vector2> uvsv;
		std::vector<uint>    indicesv;

		positionsv.assign(vertices , vertices  + numOfVertices);
		normalsv	 .assign(normales , normales  + numOfVertices);
		uvsv		 .assign(uvs	  , uvs		  + numOfVertices);
		indicesv	 .assign(triangles, triangles + numOfVertices);

		m->setPositions(positionsv);
		m->setNormals(normalsv);
		m->setUV(uvsv);
		m->setIndices(indicesv);

		return m;
	}

private:
	unsigned int mPositionBuffer;
	unsigned int mNormalBuffer;
	unsigned int mUVBuffer;
	unsigned int mIndexBuffer;

	GraphicLibrary* gl;
};

#endif /*MESH_H*/