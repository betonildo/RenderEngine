#ifndef SCENE_H
#define SCENE_H


#include "OSEXport.h"
#include <vector>
#include <memory>

class Actor;
class Camera;
class Renderer;

class ENGINE_API Scene {

public:
    Scene();
    ~Scene();
    virtual void start() = 0;
    virtual void update() = 0;
    void add(std::shared_ptr<Actor> actor);

private:

    bool mCachedRenderersValid;
    bool mCachedCamerasValid;

    std::vector< std::shared_ptr<Actor> > mActors;
    std::vector< Renderer* > mCachedRenderers;
    std::vector< Camera* > mCachedCameras;

    void render();
};

#endif /*SCENE_H*/