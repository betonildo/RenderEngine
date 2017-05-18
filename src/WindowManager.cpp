#include "WindowManager.h"

void WindowManager::setSize(int width, int height) {
    m_width = width;
    m_height = height;
}

void WindowManager::setPosition(int x, int y) {

}

bool WindowManager::Create(const char* title) {
    
    SDL_Init(SDL_INIT_VIDEO);   // Initialize SDL2

    // defaults width and height
    m_width = 640;
    m_height = 480;

    // Create an application window with the following settings:
    m_window = SDL_CreateWindow( 
        title,                    //    const char* title
        SDL_WINDOWPOS_CENTERED,   //    int x: initial x position
        SDL_WINDOWPOS_CENTERED,   //    int y: initial y position
        m_width,                  //    int w: width, in pixels
        m_height,                 //    int h: height, in pixels
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

    //Initialize GLEW
    glewExperimental = GL_TRUE; 
    GLenum glewError = glewInit();
    if( glewError != GLEW_OK ) {
        printf( "Error initializing GLEW! %s\n", glewGetErrorString( glewError ) );
    }

    m_setupOpenGLAttributes();

	// This makes our buffer swap syncronized with the monitor's vertical refresh
	SDL_GL_SetSwapInterval(1);    

    // run!!!
    m_running = true;

    std::cout << "GLSL VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    return true;
}

bool WindowManager::Showing() {
    m_HandleEvents();
    m_callRenderers();
    return m_running;
}

void WindowManager::SwapScreen() {
    SDL_GL_SwapWindow(m_window);
}

void WindowManager::m_setupOpenGLAttributes() {
	// Set our OpenGL version.
	// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	// Turn on double buffering with a 24bit Z buffer.
	// You may need to change this to 16 or 32 for your system
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void WindowManager::m_setupOpenGLColorsAndTests() {
	
    glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
    glFrontFace(GL_CCW);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
    // // Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);
}

void WindowManager::m_HandleEvents() {
    
    Input::clearLastInputs();
   
    while (SDL_PollEvent(&m_event) != 0) {
        if (m_event.type == SDL_QUIT) {
            m_running = false;
            m_cleanUp();
        }
        
        if (m_event.type == SDL_WINDOWEVENT_MOVED) {
            SDL_Log("Window %d moved to %d,%d", m_event.window.windowID, m_event.window.data1,  m_event.window.data2);
        }

        if (
            m_event.type == SDL_KEYDOWN && m_event.key.state == SDL_PRESSED 
            || m_event.type == SDL_KEYUP && m_event.key.state == SDL_RELEASED
        ) {

            bool keyUp = m_event.type == SDL_KEYUP && !Input::m_instance->m_keyup;
            bool keyDown = m_event.type == SDL_KEYDOWN && !Input::m_instance->m_keydown;
            bool keyPressed = m_event.key.state == SDL_PRESSED;
            bool keyReleased = m_event.key.state == SDL_RELEASED;
            
            Input::m_instance->m_keyname.assign(SDL_GetScancodeName(m_event.key.keysym.scancode));
            Input::m_instance->m_keyup = keyUp;
            Input::m_instance->m_keydown = keyDown;
            Input::m_instance->m_keypressed = keyPressed;
            Input::m_instance->m_keyreleased = keyReleased;
        }
    }

    // get mouse coordinates
    SDL_GetRelativeMouseState(
        &Input::m_instance->m_pointers[0].x,
        &Input::m_instance->m_pointers[0].y
    );

    Uint32 mouseBitmask = SDL_GetMouseState(NULL, NULL);
    if (mouseBitmask & SDL_BUTTON(SDL_BUTTON_LEFT)) Input::m_instance->m_leftWasPressed = true;
    if (mouseBitmask & SDL_BUTTON(SDL_BUTTON_RIGHT)) Input::m_instance->m_rightWasPressed = true;
}

void WindowManager::m_callRenderers() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);    
	glCullFace(GL_BACK);

}

void WindowManager::m_cleanUp() {

	// Delete our OpengL context
	SDL_GL_DeleteContext(m_window);

	// Destroy our window
	SDL_DestroyWindow(m_window);

    // shutdown SDL2 image
    IMG_Quit();

	// Shutdown SDL 2
	SDL_Quit();
}
