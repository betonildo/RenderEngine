#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "Renderer.h"

class RenderManager {

public:
    void enqueueRenderer(Renderer* renderer);

private:
    std::queue<Renderer*> m_queue;
};

#endif /*RENDERMANAGER_H*/