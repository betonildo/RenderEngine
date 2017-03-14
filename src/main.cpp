#include "renderer_local_includes.h"
#include "Application.h"
#include "TestScene.h"


int main( int argc, char **argv ) {
    
    Application app("First App");
    app.initWithScene(new TestScene);
    return app.run();
}