#include "Scene.h"


void Scene::render() {
    for(auto sceneObject: m_children)
        if (!sceneObject->m_parent) {
            m_renderSceneObject(sceneObject, sceneObject->transform.getModelMatrix());
        }
}

void Scene::addChild(SceneObject* sceneObject) {
    sceneObject->m_parentScene = this;
    m_children.push_back(sceneObject);
}

void Scene::addCamera(Camera* camera) {
    m_cameras.push_back(camera);
}


void Scene::m_cleanUp() {
    // clear sceneObjects
    while(!m_children.empty()) {
        auto sceneObject = m_children.back();
        delete sceneObject;
        m_children.pop_back();
    }
}

void Scene::m_renderSceneObject(SceneObject* sceneObject, Matrix4 cumulative) {
    Matrix4 model = sceneObject->transform.getModelMatrix();
    Matrix4 concatenatedMatrix = model * cumulative;

    // render all children first
    for (auto child : sceneObject->m_children)
        m_renderSceneObject(child, concatenatedMatrix);

    // send all renderers to RenderManager to render with each Camera
    std::vector<Renderer*> objectRenderers = sceneObject->getComponents<Renderer>();
    for (auto cam : m_cameras) 
        Application::getInstance()->m_renderer.enqueueRenderersWithCameraAndTransform(objectRenderers, cam, cumulative);
}

void Scene::m_updateAllObjects() {
    for (auto child : m_children) {
        child->m_updateComponents();
    }
}