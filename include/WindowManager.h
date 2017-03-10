#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "renderer_local_includes.h"

class WindowManager {

public:

    void setSize(int width, int height);
    void setPosition(int x, int y);
    bool Create(const char* title);
    void Show();
    int Watch();

private:
    bool m_running;
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    SDL_Event m_event;
    
    void m_setupOpenGLAttributes();
    void m_HandleEvents();
    void m_callRenderers();
    void m_cleanUp();
};

#endif /*WINDOWMANAGER_H*/