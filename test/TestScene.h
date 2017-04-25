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
        addChild(one);
        cam = new Camera(Camera::ProjectionType::Orthographic);
        cam->setNearPlane(0.01f);
        cam->setFarPlane(1000.0f);
        
        r.width = 40;
        r.height = 30;
        r.x = 0;
        r.y = 0;
        cam->setViewportRect(r);
        cam->transform.setPosition(glm::vec3(0, 0, 1));
        cam->transform.setRotation(glm::quat(0, 0, 0, 1));
        addCamera(cam);

        one->addComponent<SpriteMeshRenderer>();
        one->transform.setScale(glm::vec3(3,3,3));
    }

    inline virtual void update() {

        if (Input::leftButtonPressed()) {
            glm::quat p = one->transform.getRotation();
            //p.z = 1;
            p.z += -1;
            one->transform.setRotation(p);

            // glm::vec3 q = one->transform.getPosition();
            // q.x -= 0.1f;
            // one->transform.setPosition(q);
        }

        if (Input::rightButtonPressed()) {
            glm::quat p = one->transform.getRotation();
            //p.z = 1;
            p.z += 1;
            one->transform.setRotation(p);

            // glm::vec3 q = one->transform.getPosition();
            // q.x += 0.1f;
            // one->transform.setPosition(q);
        }

        if (Input::keyReleased("R")) {
            printf("KeyUp R\n");
        }
    }

    inline void DirectionY(float flow) {

    }

    inline void DirectionX(float flow) {

    }

    inline virtual void end() {

    }
};

#endif /*TESTSCENE_H*/
