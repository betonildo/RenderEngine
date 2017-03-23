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
	Quaternion r;
	SceneObject* one;

    inline virtual void start() {
    	r.v = {0, 0, 0};
	r.s = 1;

        one = new SceneObject();
        std::cout << one->transform.getModelMatrix() << std::endl;
        addChild(one);
        Camera* cam = new Camera(Camera::ProjectionType::Orthographic);
        cam->setNearPlane(1.0f);
        cam->setFarPlane(100.0f);
        Rect r;
        r.width = 640;
        r.height = 480;
        r.x = 0;
        r.y = 1;
        cam->setViewportRect(r);
        cam->transform.setPosition(Vector3(0, 0, -1));
        cam->transform.setRotation(Quaternion(0, 0, 0, 1));
        addCamera(cam);

        one->addComponent<SpriteMeshRenderer>();
    }

    inline virtual void update() {

        if (Input::leftButtonPressed()) {
            printf("Left Pressed\n");
            Vector3 p = one->transform.getPosition();
            p.x += -0.1f;
            one->transform.setPosition(p);
        }

        if (Input::rightButtonPressed()) {
            printf("Right Pressed\n");
            Vector3 p = one->transform.getPosition();
            p.x += +0.1f;
            one->transform.setPosition(p);
        }
    }

    inline virtual void end() {

    }
};

#endif /*TESTSCENE_H*/
