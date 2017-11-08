#include "scene/Scene.h"
#include "scene/Actor.h"
#include "components/NullComponent.h"
#include "components/Renderer.h"
#include "components/Camera.h"
#include "components/Light.h"
#include <typeinfo>

#ifndef NDEBUG
    #include <iostream>
#endif

Scene::Scene() {
    mCachedRenderersValid = false;
    mCachedCamerasValid = false;
    mCachedLightsValid = false;
}

Scene::~Scene() {
    
}

void Scene::add(Actor* actor) {
    mActors.push_back(actor);

    Renderer* renderer = actor->getComponent<Renderer>();
    Camera* camera = actor->getComponent<Camera>();
    Light* light = actor->getComponent<Light>();

    bool isRenderer = renderer != nullptr & strcmp(renderer->getName(), COMPONENT_NAME(Renderer)) == 0;
    bool isCamera = camera != nullptr & strcmp(camera->getName(), COMPONENT_NAME(Camera)) == 0;
    bool isLight = light != nullptr & strcmp(light->getName(), COMPONENT_NAME(Light)) == 0;

    if (isRenderer) {
        mCachedRenderers.push_back(renderer);
        mCachedRenderersValid = false;
        std::cout << "ADDED RENDERER" << std::endl;
    }

    if (isCamera) {
        mCachedCameras.push_back(camera);
        mCachedCamerasValid = false;
        std::cout << "ADDED CAMERA" << std::endl;
    }

    if (isLight) {
        mCachedLights.push_back(light);
        mCachedLightsValid = false;
        std::cout << "ADDED LIGHT" << std::endl;
    }
}

void Scene::render() {
    for (auto camera : mCachedCameras) {

    }
}