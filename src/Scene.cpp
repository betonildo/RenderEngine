#include "Scene.h"


void Scene::render() {

    for(auto sceneObject: m_children)
        if (!sceneObject->m_parent)
            m_renderSceneObject(sceneObject); 
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

void Scene::m_renderSceneObject(SceneObject* sceneObject, Transform* cumulative = nullptr) {

    // render all children first
    for (auto child : sceneObject->m_children) {
        m_renderSceneObject(child);
    }

    for (auto cam : m_cameras) {
        // render it self
        sceneObject->render();
    }
}