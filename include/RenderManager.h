#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "renderer_local_includes.h"
#include "Renderer.h"
#include "Camera.h"
#include "Transform.h"

class Renderer;
class Camera;
class Transform;

class RenderManager {

public:
    void enqueueRenderersWithCameraAndTransform(std::vector<Renderer*>& renderers, Camera* camera, Transform* transform);
    void renderAllEnqueued();

private:
    
    std::queue<std::tuple<Camera*, Transform*, std::vector<Renderer*> > > m_queue;
};

#endif /*RENDERMANAGER_H*/