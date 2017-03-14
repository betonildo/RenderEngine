#include "SceneObject.h"

SceneObject::SceneObject() {
    m_parent = nullptr;
}

void SceneObject::addChild(SceneObject* child) {
    
    child->m_parent = this;
    m_parentScene->addChild(child);
    m_children.push_back(child);
}

void SceneObject::addComponent(Component* component) {
    m_components.push_back(component);
}