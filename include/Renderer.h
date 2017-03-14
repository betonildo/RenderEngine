#ifndef RENDERER_H
#define RENDERER_H

#include "renderer_local_includes.h"
//TODO: set correct viewport based on window format
class Renderer {

public:

private:
    std::queue<SceneObject*> m_queue;
};

#endif /*RENDERER_H*/