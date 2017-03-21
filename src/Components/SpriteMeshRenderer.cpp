#include "Components/SpriteMeshRenderer.h"

SpriteMeshRenderer::SpriteMeshRenderer() {

}

void SpriteMeshRenderer::start() {
    
}

void SpriteMeshRenderer::update() {
    
}

void SpriteMeshRenderer::end() {
    
}

void SpriteMeshRenderer::m_render(Camera* camera, Transform* transform) {
    Matrix4 M = transform->getModelMatrix();
    Matrix4 V = camera->getView();
    Matrix4 P = camera->getProjection();
    Matrix4 MVP = P * V * M;

    
}