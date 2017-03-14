#ifndef RENDERER_H
#define RENDERER_H

#include "renderer_local_includes.h"
//TODO: set correct viewport based on window format
class Renderer {

public:
    void render();
    virtual void attachData(void* data, unsigned long size);
    virtual void attachMaterial(Material* m);

};

#endif /*RENDERER_H*/