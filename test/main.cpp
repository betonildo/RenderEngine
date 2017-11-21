#include <iostream>
#include <Engine.h>
#include <memory>

const float Infinity = std::numeric_limits<float>::max();

class MyScene : public Scene {

public:
	
	Quaternion cameraRot;

    void start() {
        std::cout << "My Scene Start!" << std::endl;

		auto cameraMan = new Actor();
		auto sphereHolder = new Actor();
		auto lightHolder = new Actor();

		MeshRenderer* renderer = sphereHolder->addComponent<MeshRenderer>();
        Camera* camera = cameraMan->addComponent<Camera>();        
		Light* light = lightHolder->addComponent<Light>();

		cameraRot = cameraMan->transform.getLocalRotation();

		lightHolder->transform.setLocalPosition(Vector3(-1, 1, 5));
		light->color = {1, 1, 1};
		light->intensity = 0.9f;
		light->range = Infinity;

		auto box = Mesh::createQuad();

		sphereHolder->transform.setLocalPosition(Vector3(0, 0, -5));
		sphereHolder->transform.setLocalScale(Vector3(0.5, 0.5, 0.5));
		sphereHolder->transform.setLocalRotation(Quaternion(0, 1, 0, Math::radians(90.0f)));

		Quaternion applyRotation(0, 0, 0, 0);
		cameraMan->transform.setLocalPosition(Vector3(0, 0, 10));
		cameraMan->transform.setLocalRotation(applyRotation);

		camera->setNearPlane(0.001f);
		camera->setFarPlane(1000.0f);
		camera->setFieldOfView(45.0f);
		camera->setProjectionType(Camera::ProjectionType::Perspective);


		Material* material = new Material();
		material->specular = {0.8f, 0.0f, 0.8f};
		material->diffuse = {0.4f, 0.4f, 0.0f};
		material->shininess = 1.0f;
		renderer->setMesh(box);
		renderer->addMaterial(material);

        
		Input::addKeydownListener([=](Input::Key key) {
			Quaternion applyRotation = cameraMan->transform.getLocalRotation();
			Vector3 applyPosition = sphereHolder->transform.getLocalPosition();
			switch(key) {
				case Input::Key::W:
					applyPosition.z += 1.0f;
					break;

				case Input::Key::S:
					applyPosition.z -= 1.0f;
					break;

				case Input::Key::D:
					applyPosition.x += 1.0f;
					break;

				case Input::Key::A:
					applyPosition.x -= 1.0f;
					break;

				case Input::Key::ArrowUp:
					applyRotation.x = 1;
					applyRotation.y = 0;
					applyRotation.z = 0;
					applyRotation.w += Math::radians(10.0f);
					break;

				case Input::Key::ArrowDown:
					applyRotation.x = 1;
					applyRotation.y = 0;
					applyRotation.z = 0;
					applyRotation.w -= Math::radians(10.0f);
					break;

				case Input::Key::ArrowLeft:
					applyRotation.x = 0;
					applyRotation.y = 1;
					applyRotation.z = 0;
					applyRotation.w += Math::radians(10.0f);
					break;

				case Input::Key::ArrowRight:
					applyRotation.x = 0;
					applyRotation.y = 1;
					applyRotation.z = 0;
					applyRotation.w -= Math::radians(10.0f);
					break;
			}

			cameraMan->transform.setLocalRotation(applyRotation);
			sphereHolder->transform.setLocalPosition(applyPosition);
		});

		add(cameraMan);
		add(sphereHolder);
		add(lightHolder);
    }

	Actor* createFloor() {

	}

    void update() {

    }

};


int main( int argc, char **argv ) {

    Vector3 v = {1,1,1};

    Application app;
    app.setScene(new MyScene());
    app.start();


    return 0;
}