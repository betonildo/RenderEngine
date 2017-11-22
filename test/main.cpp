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
		material->mainTexture = Resources::loadTexture("/home/gilberto/Projects/RenderEngine/test/checkerboard.png");


		renderer->setMesh(box);
		renderer->addMaterial(material);

		Vector3* rotation = new Vector3(0, 0, 0);
        
		Input::addKeydownListener([=](Input::Key key) {
			
			Vector3 position = cameraMan->transform.getLocalPosition();
			switch(key) {
				case Input::Key::W:
					position.z += 1.0f;
					break;

				case Input::Key::S:
					position.z -= 1.0f;
					break;

				case Input::Key::D:
					position.x += 1.0f;
					break;

				case Input::Key::A:
					position.x -= 1.0f;
					break;

				case Input::Key::ArrowUp:
					rotation->x = Math::radians(10.0f);
					break;

				case Input::Key::ArrowDown:
					rotation->x -= Math::radians(10.0f);
					break;

				case Input::Key::ArrowLeft:
					rotation->z += Math::radians(10.0f);
					break;

				case Input::Key::ArrowRight:
					rotation->z -= Math::radians(10.0f);
					break;
			}

			Vector3 r = *rotation;

			cameraMan->transform.setLocalRotation(fromEuler(r));
			cameraMan->transform.setLocalPosition(position);

		});

		add(cameraMan);
		add(sphereHolder);
		add(lightHolder);
    }

	Actor* createFloor() {

	}

    void update() {

    }

	Quaternion fromEuler(const Vector3& EulerAngle) {
		Quaternion QuatAroundX = Quaternion(1.0, 0.0, 0.0, EulerAngle.x);
		Quaternion QuatAroundY = Quaternion(0.0, 1.0, 0.0, EulerAngle.y);
		Quaternion QuatAroundZ = Quaternion(0.0, 0.0, 1.0, EulerAngle.z);
		Quaternion finalOrientation = QuatAroundX * QuatAroundY * QuatAroundZ;
		return finalOrientation;
	}
};


int main( int argc, char **argv ) {

    Vector3 v = {1,1,1};

    Application app;
    app.setScene(new MyScene());
    app.start();


    return 0;
}