#ifndef BUFFER_H
#define BUFFER_H

class GraphicLibrary;
enum class BufferType;

class Buffer {

public:
    Buffer(GraphicLibrary* gl, BufferType type);

private:
    GraphicLibrary* gl;
};

#endif /*BUFFER_H*/