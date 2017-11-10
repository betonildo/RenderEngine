#include "graphics/Buffer.h"
#include "graphics/Vertex.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "assets/Mesh.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"

void Mesh::setPositionBuffer(Buffer* buffer) {
	VertexFormat vertexFormat;
	vertexFormat.attributeLocation = 0;
	vertexFormat.attributeCount = 3;
	vertexFormat.attributeType = VertexFormat::AttributeType::Float;
	vertexFormat.normalized = false;
	vertexFormat.stride = sizeof(Vertex);
	vertexFormat.offsetFirst = offsetof(Vertex, position);
	buffer->setVertexFormat(vertexFormat);
	buffer->attachData(&vertices[0], vertices.size());
	mPositionBuffer = buffer;
}

void Mesh::setNormalBuffer(Buffer* buffer) {
	VertexFormat vertexFormat;
	vertexFormat.attributeLocation = 1;
	vertexFormat.attributeCount = 3;
	vertexFormat.attributeType = VertexFormat::AttributeType::Float;
	vertexFormat.normalized = false;
	vertexFormat.stride = sizeof(Vertex);
	vertexFormat.offsetFirst = offsetof(Vertex, normal);
	buffer->setVertexFormat(vertexFormat);
	buffer->attachData(&vertices[0], vertices.size());
	mNormalBuffer = buffer;
}

void Mesh::setUVBuffer(Buffer* buffer) {
	VertexFormat vertexFormat;
	vertexFormat.attributeLocation = 0;
	vertexFormat.attributeCount = 2;
	vertexFormat.attributeType = VertexFormat::AttributeType::Float;
	vertexFormat.normalized = false;
	vertexFormat.stride = sizeof(Vertex);
	vertexFormat.offsetFirst = offsetof(Vertex, uv);
	buffer->setVertexFormat(vertexFormat);
	buffer->attachData(&vertices[0], vertices.size());
	mUVBuffer = buffer;
}

void Mesh::setIndexBuffer(Buffer* buffer) {
	ElementFormat elementFormat;
	elementFormat.mode = ElementFormat::Mode::Triangles;
	elementFormat.firstElementOffset = 0;
	elementFormat.count = indices.size();
	elementFormat.type = ElementFormat::IndexType::UnsignedInt;
	buffer->setElementFormat(elementFormat);
	buffer->attachData(&indices[0], indices.size());
	mIndexBuffer = buffer;
}

void Mesh::bind() {		
	mPositionBuffer->bind();
	mNormalBuffer->bind();
	mUVBuffer->bind();	
}

void Mesh::unbind() {
	mUVBuffer->unbind();
	mNormalBuffer->unbind();
	mPositionBuffer->unbind();
}

void Mesh::drawTriangles() {
	mIndexBuffer->drawElements();
}