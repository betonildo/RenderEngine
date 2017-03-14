#ifndef SCENE_H
#define SCENE_H

#include "renderer_local_includes.h"
#include "SceneObject.h"
#include "Renderer.h"
#include "Application.h"

class Application;
class SceneObject;
class Renderer;

class Scene {

public:
    void render();
    void addChild(SceneObject* sceneObject);
    virtual void start() = 0;
    virtual void end() = 0;

private:
    std::vector<SceneObject*> m_children;
    void m_cleanUp();
    void m_renderSceneObject(SceneObject* sceneObject);

    friend class Application;
};

#endif /*SCENE_H*/
