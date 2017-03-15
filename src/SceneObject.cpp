#include "SceneObject.h"

SceneObject::SceneObject() {
    m_parent = nullptr;
}

SceneObject::~SceneObject() {
    for(auto component : m_components) {
        component->end();
        delete component;
    }
}

void SceneObject::addChild(SceneObject* child) {
    
    child->m_parent = this;
    m_parentScene->addChild(child);
    m_children.push_back(child);
}

void SceneObject::m_updateComponents() {
    for(auto component : m_components) {
        component->update();
    }
}