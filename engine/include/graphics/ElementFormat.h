#ifndef ELEMENTFORMAT_H
#define ELEMENTFORMAT_H

struct ElementFormat {

	enum class Mode {
		Points, LineStrip, LineLoop, Lines, LineStripAdjacency, LinesAdjacency, 
		TriangleStrip, TriangleFan, Triangles, TriangleStripAdjacency, TrianglesAdjacency
	};

	enum class IndexType {
		UnsignedByte, UnsignedShort, UnsignedInt
	};

	Mode mode;
	unsigned int count;
	IndexType type;
	unsigned int firstElementOffset;
};

#endif /*ELEMENTFORMAT_H*/