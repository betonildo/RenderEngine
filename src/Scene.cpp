#include "Scene.h"


void Scene::render() {

}

void Scene::addChild(SceneObject* sceneObject) {
    std::unique_ptr<SceneObject> sceneObjectPtr(sceneObject);
    m_children.push_back(sceneObjectPtr);
}

void Scene::m_cleanUp() {
    // clear children
    while(!m_children.empty()) {
        m_children.pop_front();
    }
}