#include "Scene.h"


void Scene::render() {

    for(auto sceneObject: m_children)
        if (!sceneObject->m_parent)
            m_renderSceneObject(sceneObject, sceneObject->transform); 
}

void Scene::addChild(SceneObject* sceneObject) {
    sceneObject->m_parentScene = this;
    m_children.push_back(sceneObject);
}

void addCamera(Camera* camera) {
    m_cameras.push_back(camera);
}


void Scene::m_cleanUp() {
    // clear children
    while(!m_children.empty()) {
        auto sceneObject = m_children.back();
        delete sceneObject;
        m_children.pop_back();
    }
}

void Scene::m_renderSceneObject(SceneObject* sceneObject, Transform& cumulative) {

    // render all children first
    Transform r;
    Transform::concatenateTo(sceneObject->transform, cumulative, r);

    for (auto child : sceneObject->m_children)
        m_renderSceneObject(child, r);

    // send all renderers to RenderManager to render with each Camera
    std::vector<Renderer*> objectRenderers = sceneObject->getComponents<Renderer>();
    for (auto cam : m_cameras) 
        RenderManager::enqueueRenderers(objectRenderers, cam, cumulative);
}