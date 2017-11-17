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

		std::vector<Vector3> positions;
		positions.emplace_back(-0.5f, -0.5f, 0.0f);
		positions.emplace_back(0.5f, -0.5f, 0.0f);
		positions.emplace_back(0.0f,  0.5f, 0.0f);
					
		std::vector<Vector3> normals;
		normals.emplace_back(0.0f, 0.0f, 1.0f);
		normals.emplace_back(0.0f, 0.0f, 1.0f);
		normals.emplace_back(0.0f, 0.0f, 1.0f);

		std::vector<Vector2> uvs;
		uvs.emplace_back(0.0f, 0.0f);
		uvs.emplace_back(0.5f, 1.0f);
		uvs.emplace_back(1.0f, 0.0f);

		std::vector<unsigned int> indices({0, 1, 2});

		Mesh* mesh = new Mesh();
		mesh->setPositions(positions);
		mesh->setNormals(normals);
		mesh->setUV(uvs);
		mesh->setIndices(indices);


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