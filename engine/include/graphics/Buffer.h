#ifndef BUFFER_H
#define BUFFER_H

#include "OSExport.h"
#include "graphics/ElementFormat.h"
#include "graphics/VertexFormat.h"

class GraphicLibrary;

class ENGINE_API Buffer {

public:
	Buffer() = delete;
    explicit Buffer(unsigned int bufferLocation);
    void attachData(void* data, unsigned int length);
    void bind();
    void unbind();

	void setVertexFormat(VertexFormat vertexFormat);
	void setElementFormat(ElementFormat elementFormat);

	void drawElements();

private:
    GraphicLibrary* gl;
    void* mData;
    unsigned int mDataLength;
    unsigned int mBufferLocation;
	VertexFormat mVertexFormat;
	ElementFormat mElementFormat;
};

#endif /*BUFFER_H*/