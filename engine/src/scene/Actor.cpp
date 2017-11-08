#include "scene/Actor.h"
#include <iostream>
#include "components/Component.h"
#include "components/NullComponent.h"

NullComponent* mNullComponent = new NullComponent;

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

Component* Actor::getComponentByName(const std::string& componentName) const {
    for (auto component : mComponents)
        if (component->getName() == componentName) return component;
    return mNullComponent;
}

const std::vector<Component*>& Actor::getComponents() const {
    return mComponents;
}
