#ifndef VERTEXFORMAT_H
#define VERTEXFORMAT_H

#include "graphics/FormatType.h"
#include "graphics/GraphicLibrary.h"

struct VertexFormat {

	unsigned attributeLocation;
	unsigned attributeCount;
	FormatType attributeType;
	bool normalized;
	unsigned stride;
	unsigned offsetFirst;
	GraphicLibrary::AttributeType type;

	inline const unsigned char getElementSize() {
		return GetFormatTypeSizeInBytes(attributeType) * attributeCount;
	}
};
#endif /*VERTEXFORMAT_H*/
