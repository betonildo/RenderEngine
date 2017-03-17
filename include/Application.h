#ifndef APPLICATION_H
#define APPLICATION_H

#include "RenderManager.h"
#include "Scene.h"
#include "WindowManager.h"

class RenderManager;
class Scene;
class WindowManager;

class Application {

public:
    Application(const char* name);
    int run();
    void initWithScene(Scene* mainScene);
    void changeScene(Scene* scene);
    static Application* getInstance();
    
private:
    Scene* m_currentScene;
    WindowManager m_window;
    RenderManager m_renderer;
    static Application* m_instance;
    
    friend class Scene;
    friend class RenderManager;
};

#endif /*APPLICATION_H*/