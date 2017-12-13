#include "graphics/FormatType.h"

unsigned int FormatTypeSizeInBytes[] = {
	sizeof(unsigned char), 	// Uint8
	sizeof(unsigned short), // Uint16
	sizeof(short), 			// Int16
	sizeof(int), 			// Int32
	sizeof(unsigned int), 	// Uint32
	sizeof(float)  			// Float
};

const unsigned char GetFormatTypeSizeInBytes(const FormatType& type) {
	return FormatTypeSizeInBytes[(unsigned int)type];
}