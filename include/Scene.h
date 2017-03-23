#ifndef SCENE_H
#define SCENE_H

#include "renderer_local_includes.h"
#include "SceneObject.h"
#include "Components/Renderer.h"
#include "Application.h"
#include "Camera.h"
#include "Transform.h"

class Application;
class SceneObject;
class Renderer;
class Camera;
class Transform;

class Scene {

public:
    void render();
    void addChild(SceneObject* sceneObject);
    void addCamera(Camera* camera);
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void end() = 0;

private:
    std::vector<SceneObject*> m_children;
    std::vector<Camera*> m_cameras;
    void m_cleanUp();
    void m_renderSceneObject(SceneObject* sceneObject, const Matrix4& cumulative);
    void m_updateAllObjects();
    friend class Application;
};

#endif /*SCENE_H*/
