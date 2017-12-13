#ifndef ELEMENTFORMAT_H
#define ELEMENTFORMAT_H

#include "graphics/FormatType.h"

struct ElementFormat {

	enum class Mode {
		Points, LineStrip, LineLoop, Lines, LineStripAdjacency, LinesAdjacency, 
		TriangleStrip, TriangleFan, Triangles, TriangleStripAdjacency, TrianglesAdjacency
	};

	inline const unsigned char getSize() {
		return GetFormatTypeSizeInBytes(type) * count;
	}

	Mode mode;
	unsigned int count;
	FormatType type;
	unsigned int firstElementOffset;
};

#endif /*ELEMENTFORMAT_H*/