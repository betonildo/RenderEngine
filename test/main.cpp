#include <iostream>
#include <Engine.h>
#include <memory>
class MyScene : public Scene {

public:

    void start() {
        std::cout << "My Scene Start!" << std::endl;

		auto cameraMan = std::make_unique<Actor>();
		auto sphereHolder = std::make_unique<Actor>();
		auto lightHolder = std::make_unique<Actor>();

		MeshRenderer* renderer = sphereHolder->addComponent<MeshRenderer>();
        Camera* camera = cameraMan->addComponent<Camera>();        
		Light* light = lightHolder->addComponent<Light>();



		Mesh* mesh = new Mesh();
		mesh->vertices = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,
		};

		renderer->setMesh(mesh);


        
		add(cameraMen);
		add(sphereHolder);
		add(lightHolder);
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