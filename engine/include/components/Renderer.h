#ifndef RENDERER_H
#define RENDERER_H

#include "OSExport.h"
#include "components/Component.h"

class Camera;
class Light;

class ENGINE_API Renderer : public Component {

public:
    COMPONENT_OBJECT(Renderer)

    virtual void render() = 0;
};

#endif /*RENDERER_H*/