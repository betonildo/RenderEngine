#ifndef SCENE_H
#define SCENE_H


#include "OSExport.h"
#include <vector>
#include <memory>

class Actor;
class Camera;
class Renderer;
class Light;

class ENGINE_API Scene {

public:
    Scene();
    ~Scene();
    virtual void start() = 0;
    virtual void update() = 0;
    void add(Actor* actor);
    void render();

private:
    bool mCachedRenderersValid;
    bool mCachedCamerasValid;
    bool mCachedLightsValid;

    std::vector< Actor* > mActors;
    std::vector< Renderer* > mCachedRenderers;
    std::vector< Camera* > mCachedCameras;
    std::vector< Light* > mCachedLights;

    
};

#endif /*SCENE_H*/