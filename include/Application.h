#ifndef APPLICATION_H
#define APPLICATION_H

#include "Scene.h"
#include "WindowManager.h"
#include "RenderManager.h"

class Scene;
class WindowManager;
class RenderManager;

class Application {

public:
    Application(const char* name);
    int run();
    void initWithScene(Scene* mainScene);
    void changeScene(Scene* scene);
    Application* getInstance();
    
private:
    Scene* m_currentScene;
    WindowManager m_window;
    RenderManager m_renderer;
    static Application* m_instance;
    
};

#endif /*APPLICATION_H*/