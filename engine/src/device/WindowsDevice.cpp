#include "SDL.h"
#include "device/WindowsDevice.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"
#include "graphics/Rect.h"
#include "device/Input.h"
#include <iostream>
#include <string.h>

WindowsDevice::WindowsDevice() {
	gl = GraphicLibrarySingleton::getInstance();
}

WindowsDevice::~WindowsDevice() {

    // Close and destroy the window
    SDL_DestroyWindow(mWindow);
        
    // Clean up
    SDL_Quit();
}

void WindowsDevice::start() {
    initSDL2();
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

	//Now render the texture target to our screen
	SDL_UpdateTexture(
		mTargetTexture,
		nullptr,
		gl->getBackBuffer(),
		mWidth * 4
	);

	SDL_RenderClear(mRenderer);
	SDL_RenderCopyEx(
		mRenderer, 
		mTargetTexture, 
		NULL, 
		NULL, 
		0, 
		NULL, 
		SDL_FLIP_NONE
	);
	SDL_RenderPresent(mRenderer);
    SDL_Delay(20);
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
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_UP:
                        Input::dispatchKeydownEvent(Input::Key::ArrowUp);
                        break;
                    case SDLK_DOWN:
                        Input::dispatchKeydownEvent(Input::Key::ArrowDown);
                        break;
                    case SDLK_LEFT:
                        Input::dispatchKeydownEvent(Input::Key::ArrowLeft);
                        break;
                    case SDLK_RIGHT:
                        Input::dispatchKeydownEvent(Input::Key::ArrowRight);
                        break;
                    case SDLK_w:
                        Input::dispatchKeydownEvent(Input::Key::W);
                        break;
                    case SDLK_a:
                        Input::dispatchKeydownEvent(Input::Key::A);
                        break;
                    case SDLK_s:
                        Input::dispatchKeydownEvent(Input::Key::S);
                        break;
                    case SDLK_d:
                        Input::dispatchKeydownEvent(Input::Key::D);
                        break;

                }
                break;
        }
    }    
}

int WindowsDevice::getWidth() {
    return mWidth;
}

int WindowsDevice::getHeight() {
    return mHeight;
}

float WindowsDevice::getAspectRation() {
    return (float)mWidth/(float)mHeight;
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
        0     // flags - see below
    );
    
    // Check that the window was successfully created
    if (mWindow == NULL)
    {
        // In the case that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return;
    }

	SDL_GL_CreateContext(mWindow);

    Rect viewport = {0, 0, mWidth, mHeight};
    gl->setViewportRect(viewport);
    
	// Create a renderer to render to texture on window
	mRenderer = SDL_CreateRenderer(
		mWindow, 
		-1, 
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE
	);

	// Make a target texture to render too
	mTargetTexture = SDL_CreateTexture(
		mRenderer, 
		SDL_PIXELFORMAT_RGBA32,//SDL_GetWindowPixelFormat(mWindow),
		SDL_TEXTUREACCESS_STREAMING, 
		mWidth, 
		mHeight
	);

    mNoQuit = true;
}