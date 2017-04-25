#include "RenderManager.h"

void RenderManager::enqueueRenderersWithCameraAndTransform(std::vector<Renderer*>& renderers, Camera* camera, glm::mat4& concatenatedMatrix) {

    std::tuple<std::vector<Renderer*>, Camera*, glm::mat4> cameraRenderers(renderers, camera, concatenatedMatrix);
    m_queue.push(cameraRenderers);
}

void RenderManager::renderAllEnqueued() {

    while(!m_queue.empty()) {

        auto cameraRenderers = m_queue.front();

        std::vector<Renderer*> renderers = std::get<0>(cameraRenderers);
        Camera* camera = std::get<1>(cameraRenderers);
        glm::mat4 concatenatedMatrix = std::get<2>(cameraRenderers);

        for(auto renderer : renderers)
            renderer->m_render(camera, concatenatedMatrix);

        m_queue.pop();
    }
}