#include "Application.h"

Application::Application(const char* name) {
    m_instance = this;
    m_window.Create(name);
}

int Application::run() {
    
    while(m_window.Showing()) {
        m_currentScene->update();
        m_renderer.renderAllEnqueued();        
        m_window.SwapScreen();
    }

    return 0;
}

void Application::initWithScene(Scene* mainScene) {
    m_currentScene = mainScene;
    m_currentScene->start();
}

void Application::changeScene(Scene* scene) {
    if (m_currentScene) {
        m_currentScene->end();
        m_currentScene->m_cleanUp();
    }
    m_currentScene = scene;
    m_currentScene->start(); 
}

Application* Application::getInstance() {
    return m_instance;
}