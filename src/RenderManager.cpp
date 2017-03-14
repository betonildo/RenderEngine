#include "RenderManager.h"

void RenderManager::enqueueRenderersWithCamera(std::vector<Renderer*>& renderers, Camera* camera) {

    std::pair<Camera*, std::vector<Renderer*> > cameraRenderers(camera, renderers);
    m_queue.push(cameraRenderers);
}

void RenderManager::renderAllEnqueued() {

    while(!m_queue.empty()) {

        auto cameraRenderers = m_queue.front();

        Camera* camera = cameraRenderers.first;
        std::vector<Renderer*> renderers = cameraRenderers.seconds;

        

        m_queue.pop();
    }
}