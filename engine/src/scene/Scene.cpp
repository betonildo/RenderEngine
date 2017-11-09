#include "scene/Scene.h"
#include "scene/Actor.h"
#include "components/NullComponent.h"
#include "components/Renderer.h"
#include "components/Camera.h"
#include "components/Light.h"
#include "graphics/GraphicLibrary.h"
#include "graphics/GraphicLibrarySingleton.h"
#include <typeinfo>

Scene::Scene() {
    mCachedRenderersValid = false;
    mCachedCamerasValid = false;
    mCachedLightsValid = false;
    gl = GraphicLibrarySingleton::getInstance();
}

Scene::~Scene() {
    
}

void Scene::add(Actor* actor) {
    mActors.push_back(actor);

    Renderer* renderer = actor->getComponent<Renderer>();
    Camera* camera = actor->getComponent<Camera>();
    Light* light = actor->getComponent<Light>();

    bool isRenderer = renderer != nullptr;// & strcmp(renderer->getName(), COMPONENT_NAME(Renderer)) == 0;
    bool isCamera = camera != nullptr;// & strcmp(camera->getName(), COMPONENT_NAME(Camera)) == 0;
    bool isLight = light != nullptr;// & strcmp(light->getName(), COMPONENT_NAME(Light)) == 0;

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
    for (auto camera : mCachedCameras)
        for (auto renderer : mCachedRenderers)
            renderer->render(camera, mCachedLights[0], mCachedLights.size());
    gl->processCommandList();
}