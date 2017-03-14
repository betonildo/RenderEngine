#include "Application.h"

Application::Application(const char* name) {
    m_instance = this;
    m_window.Create(name);
}

int Application::run() {
    m_window.Show();
    return m_window.Watch(m_renderer->render);
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
}

Application* Application::getInstance() {
    return m_instance;
}