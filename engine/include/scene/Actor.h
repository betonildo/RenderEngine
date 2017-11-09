#ifndef ACTOR_H
#define ACTOR_H

#include "OSExport.h"
#include "scene/Transform.h"
#include <vector>
#include <string>
#include <typeinfo>

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
    void addComponent() { addComponent(new ComponentType()); }

    template <typename ComponentType>
    ComponentType* getComponent() const {
        for (auto component : mComponents) {
            ComponentType* componentCast = dynamic_cast<ComponentType*>(component);
            if (componentCast != nullptr) return componentCast;
        }
        return nullptr;
    }

    void removeComponent(Component* component);
    const std::vector<Component*>& getComponents() const;
    
private:
    std::vector<Component*> mComponents;
    
    void addComponent(Component* component);
    Component* getComponentByName(const std::type_info& type_info) const;    
};

#endif /*ACTOR_H*/