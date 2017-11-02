#include "GL/glew.h"
#include "SDL.h"
#include "SDL_opengl.h"
#include "device/WindowsDevice.h"

#include <iostream>
#include <string.h>

WindowsDevice::WindowsDevice() {

}

WindowsDevice::~WindowsDevice() {

    // Close and destroy the window
    SDL_DestroyWindow(mWindow);
        
    // Clean up
    SDL_Quit();
}

void WindowsDevice::start() {
    initSDL2();
    initGlew();
}

void WindowsDevice::setTitle(const char* title) {
    mTitle = (char*)title;
}

void WindowsDevice::setWidth(int width) {
    mWidth = width;
}

void WindowsDevice::setHeight(int height) {
    mHeight = height;
}

void WindowsDevice::swapBuffers() {
    SDL_GL_SwapWindow(mWindow);
}

bool WindowsDevice::isAvailable() {
    return mNoQuit;
}

void WindowsDevice::pollEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {

        switch(event.type) {
            case SDL_QUIT:
                mNoQuit = false;
                break;
        }
    }    
}

void WindowsDevice::initSDL2() {
    
    bool sdl2WasInit = SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Init(SDL_INIT_EVERYTHING); // Initialize SDL2

    // Create an application window with the following settings:
    mWindow = SDL_CreateWindow(
        mTitle,        // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        mWidth,                     // width, in pixels
        mHeight,                     // height, in pixels
        SDL_WINDOW_OPENGL  | SDL_WINDOW_RESIZABLE     // flags - see below
    );
    
    // Check that the window was successfully created
    if (mWindow == NULL)
    {
        // In the case that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return;
    }
    
    // Create an OpenGL context associated with the window.
    SDL_GLContext glcontext = SDL_GL_CreateContext(mWindow);

    mNoQuit = true;
}

void WindowsDevice::initGlew() {
    glewExperimental = GL_TRUE;
    GLenum glewInitResponse = glewInit();
    if (glewInitResponse != GLEW_OK) {
        std::cout << "Glew Error: " << glewGetErrorString(glewInitResponse) << std::endl;
    }
}