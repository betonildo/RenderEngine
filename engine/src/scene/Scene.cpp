#include "scene/Scene.h"
#include "scene/Actor.h"
#include "components/NullComponent.h"
#include "components/Renderer.h"
#include "components/Camera.h"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::add(std::shared_ptr<Actor> actor) {
    mActors.push_back(actor);

    Renderer* renderer = actor->getComponentReference<Renderer>();
    if (renderer != nullptr && renderer->getName() == COMPONENT_NAME(Renderer)) {
        mCachedRenderers.push_back(renderer);
        mCachedRenderersValid = false;
    }

    Camera* camera = actor->getComponentReference<Camera>();
    if (camera != nullptr && camera->getName() == COMPONENT_NAME(Camera)) {
        mCachedCameras.push_back(camera);
        mCachedCamerasValid = false;
    }
}

void Scene::render() {


}