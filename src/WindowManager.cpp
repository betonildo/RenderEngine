#include "WindowManager.h"

void WindowManager::setSize(int width, int height) {

}

void WindowManager::setPosition(int x, int y) {

}

bool WindowManager::Create(const char* title) {
    
    SDL_Init(SDL_INIT_VIDEO);   // Initialize SDL2

    // Create an application window with the following settings:
    m_window = SDL_CreateWindow( 
        title,                    //    const char* title
        SDL_WINDOWPOS_CENTERED,   //    int x: initial x position
        SDL_WINDOWPOS_CENTERED,   //    int y: initial y position
        640,                      //    int w: width, in pixels
        480,                      //    int h: height, in pixels
        SDL_WINDOW_OPENGL         //    Uint32 flags: window options, see docs
    );

    // Check that the window was successfully made
    if(m_window == NULL){   
        // In the event that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    
    m_glContext = SDL_GL_CreateContext(m_window);

    m_setupOpenGLAttributes();

	// This makes our buffer swap syncronized with the monitor's vertical refresh
	SDL_GL_SetSwapInterval(1);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
    

    // run!!!
    m_running = true;

    return true;
}

void WindowManager::Show() {

}

int  WindowManager::Watch() {
    while(m_running) {
        m_HandleEvents();
        m_callRenderers();
    }

    return 0;
}

void WindowManager::m_setupOpenGLAttributes() {
	// Set our OpenGL version.
	// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Turn on double buffering with a 24bit Z buffer.
	// You may need to change this to 16 or 32 for your system
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void WindowManager::m_HandleEvents() {
   
    if (SDL_PollEvent(&m_event) != 0) {
        if (m_event.type == SDL_QUIT) {
            m_cleanUp();
            m_running = false;
        }
        
        if (m_event.type == SDL_WINDOWEVENT_MOVED)
            SDL_Log("Window %d moved to %d,%d",
                    m_event.window.windowID, m_event.window.data1,
                    m_event.window.data2);
    }
}

void WindowManager::m_callRenderers() {
    SDL_GL_SwapWindow(m_window);
}

void WindowManager::m_cleanUp() {

	// Delete our OpengL context
	SDL_GL_DeleteContext(m_window);

	// Destroy our window
	SDL_DestroyWindow(m_window);

	// Shutdown SDL 2
	SDL_Quit();
}