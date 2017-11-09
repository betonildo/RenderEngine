#include "scene/Actor.h"
#include <iostream>
#include "components/Component.h"

Actor::Actor() {

}

Actor::~Actor() {
    for (auto component : mComponents)
        delete component;
}

void Actor::addComponent(Component* component) {
    component->bindActor(std::shared_ptr<Actor>(this));
    mComponents.push_back(component);
}

void Actor::removeComponent(Component* component) {
    unsigned int componentIndexToRemove = 0;
    while (componentIndexToRemove < mComponents.size()) {
        if (mComponents[componentIndexToRemove] == component) break;
        componentIndexToRemove++;
    }

    if (componentIndexToRemove < mComponents.size())
        mComponents.erase(mComponents.begin() + componentIndexToRemove);
}

Component* Actor::getComponentByName(const std::type_info& type_info) const {
    for (auto component : mComponents) {
        std::cout << component->getName() << std::endl;
        std::cout << type_info.name() << std::endl;
        if (strcmp(component->getName(), type_info.name()) == 0)
            return component;
    }
    return nullptr;
}

const std::vector<Component*>& Actor::getComponents() const {
    return mComponents;
}
