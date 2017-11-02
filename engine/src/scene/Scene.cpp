#include "scene/Scene.h"
#include "scene/Actor.h"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::add(Actor* actor) {
    mActors.push_back(actor);
}

void Scene::render() {

}