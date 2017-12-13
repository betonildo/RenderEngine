#include "assets/Mesh.h"
#include "graphics/Vertex.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "graphics/FormatType.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"

Mesh::Mesh() {
	gl = GraphicLibrarySingleton::getInstance();
	mPositionBuffer = gl->generateVertexBuffer();
	mNormalBuffer = gl->generateVertexBuffer();
	mUVBuffer = gl->generateVertexBuffer();
	mIndexBuffer = gl->generateIndexBuffer();
}

Mesh::Mesh(const Mesh& other) {
	gl = other.gl;
	mPositionBuffer = other.mPositionBuffer;
	mNormalBuffer = other.mNormalBuffer;
	mUVBuffer = other.mUVBuffer;
	mIndexBuffer = other.mIndexBuffer;
}

void Mesh::setPositions(std::vector<Vector3>& positions) {
	VertexFormat vertexFormat;
	vertexFormat.attributeLocation = 0;
	vertexFormat.attributeCount = 3;
	vertexFormat.attributeType = FormatType::Float;
	vertexFormat.normalized = false;
	vertexFormat.stride = 0;
	vertexFormat.offsetFirst = 0;
	vertexFormat.type = GraphicLibrary::AttributeType::Position;

	gl->bindVertexBuffer(mPositionBuffer);
	gl->bindVertexBufferData(vertexFormat, positions);
	gl->unbindVertexBuffer(mPositionBuffer);
}

void Mesh::setNormals(std::vector<Vector3>& normals) {
	VertexFormat vertexFormat;
	vertexFormat.attributeLocation = 1;
	vertexFormat.attributeCount = 3;
	vertexFormat.attributeType = FormatType::Float;
	vertexFormat.normalized = false;
	vertexFormat.stride = 0;
	vertexFormat.offsetFirst = 0;
	vertexFormat.type = GraphicLibrary::AttributeType::Normal;

	gl->bindVertexBuffer(mNormalBuffer);
	gl->bindVertexBufferData(vertexFormat, normals);
	gl->unbindVertexBuffer(mNormalBuffer);
}

void Mesh::setUV(std::vector<Vector2>& uvs) {
	VertexFormat vertexFormat;
	vertexFormat.attributeLocation = 0;
	vertexFormat.attributeCount = 2;
	vertexFormat.attributeType = FormatType::Float;
	vertexFormat.normalized = false;
	vertexFormat.stride = 0;
	vertexFormat.offsetFirst = 0;
	vertexFormat.type = GraphicLibrary::AttributeType::UV0;

	gl->bindVertexBuffer(mUVBuffer);
	gl->bindVertexBufferData(vertexFormat, uvs);
	gl->unbindVertexBuffer(mUVBuffer);
}

void Mesh::setIndices(std::vector<unsigned int>& indices) {
	ElementFormat elementFormat;
	elementFormat.mode = ElementFormat::Mode::Triangles;
	elementFormat.firstElementOffset = 0;
	elementFormat.count = indices.size();
	elementFormat.type = FormatType::Uint32;

	gl->bindIndexBuffer(mIndexBuffer);
	gl->bindIndexBufferData(elementFormat, indices);
	gl->unbindIndexBuffer(mIndexBuffer);
}

void Mesh::drawTriangles() {
	gl->enableAttribute(mPositionBuffer);
	gl->enableAttribute(mNormalBuffer);
	gl->enableAttribute(mUVBuffer);
	gl->bindIndexBuffer(mIndexBuffer);
	gl->drawElements();
	gl->unbindIndexBuffer(mIndexBuffer);
	gl->disableAttribute(mUVBuffer);
	gl->disableAttribute(mNormalBuffer);
	gl->disableAttribute(mPositionBuffer);
}
