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
    void addChild(SceneObject* child);
    void attachRenderer(Renderer* renderer);

    void addComponent(Component* component);

    template <class T>
    inline T* getComponent() {
        for(auto component : m_components)
            if (T* downcastedComponent = dynamic_cast<T*>(component))
                return downcastedComponent;
        return nullptr;
    }

    template <class T>
    inline std::vector<T*>& getComponents() {

        std::vector<T*>* gotComponents = new std::vector<T>;
        for(auto component : m_components)
            if (T* downcastedComponent = dynamic_cast<T*>(component))
                gotComponents->push_back(downcastedComponent);

        return *gotComponents;
    }

private:
    
    Scene* m_parentScene;
    SceneObject* m_parent;

    std::vector<SceneObject*> m_children;
    std::vector<Component*> m_components;

    void m_updateComponents();

    friend class Scene;
};

#endif /*SCENEOBJECT_H*/