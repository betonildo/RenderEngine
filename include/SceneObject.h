#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "renderer_local_includes.h"
#include "Camera.h"
#include "Scene.h"
#include "Renderer.h"
#include "Transform.h"

class Scene;
class Renderer;
class Transform;

class SceneObject {

public:
    SceneObject();
    void addChild(SceneObject* child);
    void attachRenderer(Renderer* renderer);

private:

    friend class Scene;

    Transform* m_transform;
    Renderer* m_renderer;
    Scene* m_parentScene;
    SceneObject* m_parent;
    std::vector<SceneObject*> m_children;

    void m_renderWithCameraAndParentTransform(Transform* parentTransform, Camera* camera);
};

#endif /*SCENEOBJECT_H*/