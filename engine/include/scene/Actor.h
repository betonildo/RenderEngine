#ifndef ACTOR_H
#define ACTOR_H

#include "OSExport.h"
#include "scene/Transform.h"
#include <vector>

#ifndef COMPONENT_NAME
    #define COMPONENT_NAME(COMPONENT_TYPE) #COMPONENT_TYPE
#endif

class Component;

class ENGINE_API Actor {

public:
    Transform transform;

    Actor();
    ~Actor();

    template <typename ComponentType>
    void addComponent() {
        addComponent(new ComponentType());
    }

    template <typename ComponentType>
    ComponentType* getComponentReference() const {
        Component* gotComponent = getComponentReferenceByName(COMPONENT_NAME(ComponentType));
        return reinterpret_cast<ComponentType*>(gotComponent);
    }

    void removeComponent(Component* component);
    const std::vector<Component*>& getComponents() const;
    
private:
    std::vector<Component*> mComponents;
    
    void addComponent(Component* component);
    Component* getComponentReferenceByName(const std::string& componentName) const;    
};

#endif /*ACTOR_H*/