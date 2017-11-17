#ifndef VERTEXFORMAT_H
#define VERTEXFORMAT_H

#include "graphics/GraphicLibrary.h"

struct VertexFormat {
	enum class AttributeType {
		Uint8,
		Uint16,
		Int16,
		Int32,
		Uint32,
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

	inline static const unsigned char AttributeByteSizes(AttributeType type) {

		unsigned int AttributesByteSizes[] = {
			sizeof(unsigned char), 	// Uint8
			sizeof(unsigned short), // Uint16
			sizeof(short), 			// Int16
			sizeof(int), 			// Int32
			sizeof(unsigned int), 	//Uint32
			sizeof(float)  			// Float
		};

		return AttributesByteSizes[(unsigned int)type];
	}
};
#endif /*VERTEXFORMAT_H*/
