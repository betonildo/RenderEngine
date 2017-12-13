#ifndef FORMATTYPE_H
#define FORMATTYPE_H

unsigned int FormatTypeSizeInBytes[] = {
	sizeof(unsigned char), 	// Uint8
	sizeof(unsigned short), // Uint16
	sizeof(short), 			// Int16
	sizeof(int), 			// Int32
	sizeof(unsigned int), 	// Uint32
	sizeof(float)  			// Float
};

enum class FormatType {
    Uint8,
    Uint16,
    Int16,
    Int32,
    Uint32,
    Float,
    Count
};

inline static const unsigned char GetFormatTypeSizeInBytes(const FormatType& type) {
    return FormatTypeSizeInBytes[(unsigned int)type];
}

#endif /*FORMATTYPE_H*/