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
        return reinterpret_cast<ComponentType*>(getComponentByName(typeid(ComponentType))); 
    }

    void removeComponent(Component* component);
    const std::vector<Component*>& getComponents() const;
    
private:
    std::vector<Component*> mComponents;
    
    void addComponent(Component* component);
    Component* getComponentByName(const std::type_info& type_info) const;    
};

#endif /*ACTOR_H*/