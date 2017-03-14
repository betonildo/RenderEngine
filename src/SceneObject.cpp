#include "SceneObject.h"

SceneObject::SceneObject() {
    m_parent = nullptr;
}

void SceneObject::addChild(SceneObject* child) {
    
    child->m_parent = this;
    m_parentScene->addChild(child);
    m_children.push_back(child);
}

void SceneObject::attachRenderer(Renderer* renderer) {
    m_renderer = renderer;
}

void SceneObject::m_renderWithCameraAndParentTransform(Transform* parentTransform, Camera* camera) {
    // TODO: add to renderer pipeline logic
    Transform t = m_transform->returnAddedTransformWithParent(parentTransform);
    m_renderer->enqueue(this, resulting); /// DON'T KNOW YET
}