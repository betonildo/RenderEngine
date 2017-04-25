#include "renderer_local_includes.h"
#include "Components/Renderer.h"
#include "Camera.h"
#include "Transform.h"

#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

class Renderer;
class Camera;
class Transform;

class RenderManager {

public:
    void enqueueRenderersWithCameraAndTransform(std::vector<Renderer*>& renderers, Camera* camera, glm::mat4& concatenatedMatrix);
    void renderAllEnqueued();

private:
    
    std::queue<std::tuple<std::vector<Renderer*>, Camera*, glm::mat4 > > m_queue;
};

#endif /*RENDERMANAGER_H*/