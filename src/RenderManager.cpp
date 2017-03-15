#include "RenderManager.h"

void RenderManager::enqueueRenderersWithCameraAndTransform(std::vector<Renderer*>& renderers, Camera* camera, Transform* transform) {

    std::tuple<std::vector<Renderer*>, Camera*, Transform*> cameraRenderers(renderers, camera, transform);
    m_queue.push(cameraRenderers);
}

void RenderManager::renderAllEnqueued() {

    while(!m_queue.empty()) {

        auto cameraRenderers = m_queue.front();

        std::vector<Renderer*> renderers = std::get<0>(cameraRenderers);
        Camera* camera = std::get<1>(cameraRenderers);
        Transform* transform = std::get<2>(cameraRenderers);

        for(auto renderer : renderers)
            renderer->m_render(camera, transform);

        m_queue.pop();
    }
}