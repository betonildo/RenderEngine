#include <iostream>
#include <Engine.h>
#include <memory>

class MyScene : public Scene {

public:

    void start() {
        std::cout << "My Scene Start!" << std::endl;

        auto actor = new Actor();
        

        actor->addComponent<Camera>();
        actor->addComponent<Renderer>();

        add(actor);
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