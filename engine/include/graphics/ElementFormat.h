#ifndef ELEMENTFORMAT_H
#define ELEMENTFORMAT_H

struct ElementFormat {

	enum class Mode {
		Points, LineStrip, LineLoop, Lines, LineStripAdjacency, LinesAdjacency, 
		TriangleStrip, TriangleFan, Triangles, TriangleStripAdjacency, TrianglesAdjacency
	};

	enum class IndexType {
		UnsignedByte, UnsignedShort, UnsignedInt, Count
	};

	inline static const unsigned char IndexTypeSizes(IndexType type) {

		unsigned int IndexTypeSize[] = {
			sizeof(unsigned char),
			sizeof(unsigned short),
			sizeof(unsigned int)
		};

		return IndexTypeSize[(unsigned int)type];
	}

	Mode mode;
	unsigned int count;
	IndexType type;
	unsigned int firstElementOffset;
};

#endif /*ELEMENTFORMAT_H*/