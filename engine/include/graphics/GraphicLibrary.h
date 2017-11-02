#ifndef GRAPHICLIBRARY_H
#define GRAPHICLIBRARY_H

//TODO: Write on function demand
class GraphicLibrary {

public:
    virtual void upload(void* data, unsigned short typeSize, unsigned int length) = 0;
    virtual void updateTexture(void* data, unsigned int length) = 0;    
};

#endif /*GRAPHICLIBRARY_H*/