#include "scene/Scene.h"
#include "scene/Actor.h"
#include "components/NullComponent.h"
#include "components/Renderer.h"
#include "components/Camera.h"
#include "components/Light.h"
#include "graphics/GraphicLibrary.h"
#include "graphics/GraphicLibrarySingleton.h"
#include <typeinfo>
#include <iostream>

Scene::Scene() {
    mCachedRenderersValid = false;
    mCachedCamerasValid = false;
    mCachedLightsValid = false;
}

Scene::~Scene() {
    
}

void Scene::preStart() {
    gl = GraphicLibrarySingleton::getInstance();
}

void Scene::add(Actor* actor) {
    mActors.push_back(actor);

    Renderer* renderer = actor->getComponent<Renderer>();
    Camera* camera = actor->getComponent<Camera>();
    Light* light = actor->getComponent<Light>();

    bool isRenderer = renderer != nullptr;
    bool isCamera = camera != nullptr;
    bool isLight = light != nullptr;

    if (isRenderer) {
        mCachedRenderers.push_back(renderer);
        mCachedRenderersValid = false;
    }

    if (isCamera) {
        mCachedCameras.push_back(camera);
        mCachedCamerasValid = false;
    }

    if (isLight) {
        mCachedLights.push_back(light);
        mCachedLightsValid = false;
    }
}

void Scene::render() {
    gl->clearObjectList();
    gl->pushLights(mCachedLights[0], mCachedLights.size());

    for (auto camera : mCachedCameras) {
        gl->pushCamera(camera);
        for (auto renderer : mCachedRenderers)
            renderer->render();
    }
    gl->processObjectList();
}