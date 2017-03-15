#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "renderer_local_includes.h"
#include "Camera.h"
#include "Scene.h"
#include "Transform.h"
#include "Components/Component.h"

class Scene;
class Transform;
class Component;

class SceneObject {

public:

    Transform transform;

    SceneObject();
    ~SceneObject();
    void addChild(SceneObject* child);

    template <class T>
    inline void addComponent();

    template <class T>
    inline T* getComponent();

    template <class T>
    inline std::vector<T*>& getComponents();

private:
    
    Scene* m_parentScene;
    SceneObject* m_parent;

    std::vector<SceneObject*> m_children;
    std::vector<Component*> m_components;

    void m_updateComponents();

    friend class Scene;
};

// Implementation

template <class T>
inline void SceneObject::addComponent() {
    T* component = new T;
    component->m_sceneObject = this;
    component->start();
    m_components.push_back(component);
}

template <class T>
inline T* SceneObject::getComponent() {
    for(auto component : m_components)
        if (T* downcastedComponent = dynamic_cast<T*>(component))
            return downcastedComponent;
    return nullptr;
}

template <class T>
inline std::vector<T*>& SceneObject::getComponents() {

    std::vector<T*>* gotComponents = new std::vector<T*>;
    for(auto component : m_components)
        if (T* downcastedComponent = dynamic_cast<T*>(component))
            gotComponents->push_back(downcastedComponent);

    return *gotComponents;
}

#endif /*SCENEOBJECT_H*/