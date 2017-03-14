#ifndef RENDERER_H
#define RENDERER_H

#include "renderer_local_includes.h"
#include "Component.h"

//TODO: set correct viewport based on window format
class Renderer : public Component {

public:
    void render();
    virtual void attachData(void* data, unsigned long size);
    virtual void attachMaterial(Material* m);

private:
    // TODO: insert sprite notation

};

#endif /*RENDERER_H*/