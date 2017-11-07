#include "components/Component.h"

Component::Component() {

}

void Component::update(float dt) {
    
}

void Component::bindActor(std::shared_ptr<Actor> actor) {
    if (!mActorBound) {
        mActor = actor;
        mActorBound = true;
    }
}