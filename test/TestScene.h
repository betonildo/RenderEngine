#include "Scene.h"
#include "Components/SpriteMeshRenderer.h"
#include "Camera.h"

#ifndef TESTSCENE_H
#define TESTSCENE_H

class SpriteMeshRenderer;
class Camera;

class TestScene : public Scene {

public:
    inline virtual void start() {
        SceneObject* one = new SceneObject();
        addChild(one);
        Camera* cam = new Camera(Camera::ProjectionType::Orthographic);
        addCamera(cam);

        one->addComponent<SpriteMeshRenderer>();

        Material m;
        m.load("resources/test/Materials/Default_SpriteMaterial.mat");
    }

    inline virtual void update() {
        
    }

    inline virtual void end() {

    }
};

#endif /*TESTSCENE_H*/