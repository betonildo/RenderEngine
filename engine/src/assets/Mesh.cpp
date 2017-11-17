#include "graphics/Vertex.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "assets/Mesh.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"

Mesh::Mesh() {
	gl = GraphicLibrarySingleton::getInstance();
	mPositionBuffer = gl->generateVertexBuffer();
	mNormalBuffer = gl->generateVertexBuffer();
	mUVBuffer = gl->generateVertexBuffer();
	mIndexBuffer = gl->generateIndexBuffer();
}

void Mesh::setPositions(std::vector<Vector3>& positions) {
	VertexFormat vertexFormat;
	vertexFormat.attributeLocation = 0;
	vertexFormat.attributeCount = 3;
	vertexFormat.attributeType = VertexFormat::AttributeType::Float;
	vertexFormat.normalized = false;
	vertexFormat.stride = 0;
	vertexFormat.offsetFirst = 0;
	vertexFormat.type = GraphicLibrary::AttributeType::Position;

	gl->bindVertexBuffer(mPositionBuffer);
	gl->bindVertexBufferData(positions.data(), positions.size());
	gl->setVertexFormat(vertexFormat);
	gl->unbindVertexBuffer(mPositionBuffer);
}

void Mesh::setNormals(std::vector<Vector3>& normals) {
	VertexFormat vertexFormat;
	vertexFormat.attributeLocation = 1;
	vertexFormat.attributeCount = 3;
	vertexFormat.attributeType = VertexFormat::AttributeType::Float;
	vertexFormat.normalized = false;
	vertexFormat.stride = 0;
	vertexFormat.offsetFirst = 0;
	vertexFormat.type = GraphicLibrary::AttributeType::Normal;

	gl->bindVertexBuffer(mNormalBuffer);
	gl->bindVertexBufferData(normals.data(), normals.size());
	gl->setVertexFormat(vertexFormat);
	gl->unbindVertexBuffer(mNormalBuffer);
}

void Mesh::setUV(std::vector<Vector2>& uvs) {
	VertexFormat vertexFormat;
	vertexFormat.attributeLocation = 0;
	vertexFormat.attributeCount = 2;
	vertexFormat.attributeType = VertexFormat::AttributeType::Float;
	vertexFormat.normalized = false;
	vertexFormat.stride = 0;
	vertexFormat.offsetFirst = 0;
	vertexFormat.type = GraphicLibrary::AttributeType::UV0;

	gl->bindVertexBuffer(mUVBuffer);
	gl->bindVertexBufferData(uvs.data(), uvs.size());
	gl->setVertexFormat(vertexFormat);
	gl->unbindVertexBuffer(mUVBuffer);
}

void Mesh::setIndices(std::vector<unsigned int>& indices) {
	ElementFormat elementFormat;
	elementFormat.mode = ElementFormat::Mode::Triangles;
	elementFormat.firstElementOffset = 0;
	elementFormat.count = indices.size();
	elementFormat.type = ElementFormat::IndexType::UnsignedInt;

	gl->bindIndexBuffer(mIndexBuffer);
	gl->bindIndexBufferData(indices.data(), indices.size());
	gl->setElementFormat(elementFormat);
	gl->unbindIndexBuffer(mIndexBuffer);
}

void Mesh::drawTriangles() {
	gl->enableAttribute(mPositionBuffer);
	gl->enableAttribute(mNormalBuffer);
	gl->enableAttribute(mUVBuffer);
	gl->bindIndexBuffer(mIndexBuffer);
	gl->drawElements();
	gl->disableAttribute(mPositionBuffer);
	gl->disableAttribute(mNormalBuffer);
	gl->disableAttribute(mUVBuffer);
	gl->unbindIndexBuffer(mIndexBuffer);
}
