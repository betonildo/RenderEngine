#ifndef VERTEXFORMAT_H
#define VERTEXFORMAT_H

#include "graphics/GraphicLibrary.h"

struct VertexFormat {
	enum class AttributeType {
		Uint8,
		Uint10,
		Uint16,
		Int16,
		Int32,
		Half,
		Float,
		Count
	};

	unsigned attributeLocation;
	unsigned attributeCount;
	AttributeType attributeType;
	bool normalized;
	unsigned stride;
	unsigned offsetFirst;
	GraphicLibrary::AttributeType type;
};
#endif /*VERTEXFORMAT_H*/
