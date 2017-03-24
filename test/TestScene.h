#include "Scene.h"
#include "Components/SpriteMeshRenderer.h"
#include "Camera.h"
#include "Input.h"

#ifndef TESTSCENE_H
#define TESTSCENE_H

class SpriteMeshRenderer;
class Camera;

class TestScene : public Scene {

public:
	SceneObject* one;
    Camera* cam;
    Rect r;

    inline virtual void start() {

        one = new SceneObject();
        std::cout << one->transform.getModelMatrix() << std::endl;
        addChild(one);
        cam = new Camera(Camera::ProjectionType::Orthographic);
        cam->setNearPlane(0.01f);
        cam->setFarPlane(1000.0f);
        
        r.width = 40;
        r.height = 30;
        r.x = 0;
        r.y = 0;
        cam->setViewportRect(r);
        cam->transform.setPosition(Vector3(0, 0, 1));
        cam->transform.setRotation(Quaternion(0, 0, 0, 1));
        addCamera(cam);

        one->addComponent<SpriteMeshRenderer>();
        one->transform.setScale(Vector3(3,3,3));
    }

    inline virtual void update() {

        if (Input::leftButtonPressed()) {
            printf("Left Pressed\n");
            Quaternion p = one->transform.getRotation();
            p.v = {1, 0, 1};
            p.s += -0.1f;
            one->transform.setRotation(p);
        }

        if (Input::rightButtonPressed()) {
            printf("Right Pressed\n");
            Quaternion p = one->transform.getRotation();
            p.v = {1, 0, 1};
            p.s += +0.1f;
            one->transform.setRotation(p);
        }
    }

    inline virtual void end() {

    }
};

#endif /*TESTSCENE_H*/
