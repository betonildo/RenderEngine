#include "components/Component.h"
#include "scene/Transform.h"
#include "scene/Actor.h"

Component::Component() {

}

Transform& Component::getTransform() const {
    return mActor->transform;
}

void Component::update(float dt) {
    
}

void Component::bindActor(std::shared_ptr<Actor> actor) {
    if (!mActorBound) {
        mActor = actor;
        mActorBound = true;
    }
}

