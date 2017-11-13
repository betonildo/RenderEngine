#include <iostream>
#include <Engine.h>
#include <memory>

class MyScene : public Scene {

public:

    void start() {
        std::cout << "My Scene Start!" << std::endl;

		auto cameraMan = new Actor();
		auto sphereHolder = new Actor();
		auto lightHolder = new Actor();

		MeshRenderer* renderer = sphereHolder->addComponent<MeshRenderer>();
        Camera* camera = cameraMan->addComponent<Camera>();        
		Light* light = lightHolder->addComponent<Light>();



		Mesh* mesh = new Mesh();
		mesh->vertices.emplace_back(-0.5f, -0.5f, 0.0f);
		mesh->vertices.emplace_back( 0.5f, -0.5f, 0.0f);
		mesh->vertices.emplace_back( 0.0f,  0.5f, 0.0f);
		mesh->indices.push_back(0);
		mesh->indices.push_back(1);
		mesh->indices.push_back(2);


		renderer->setMesh(mesh);


        
		add(cameraMan);
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