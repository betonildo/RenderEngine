#include "Scene.h"


void Scene::render() {

}

void Scene::addChild(SceneObject* sceneObject) {
    m_children.push_back(sceneObject);
}

void Scene::m_cleanUp() {
    // clear children
    while(!m_children.empty()) {
        auto sceneObject = m_children.back();
        delete sceneObject;
        m_children.pop_back();
    }
}