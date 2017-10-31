#include "GL/glew.h"
#include "SDL.h"
#include "SDL_opengl.h"
#include "Engine.h"
#include <iostream>

void Engine::start_monolitic()
{
    bool sdl2WasInit = SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2

    // Create an application window with the following settings:
    SDL_Window *window = SDL_CreateWindow(
        "Engine",        // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        640,                     // width, in pixels
        480,                     // height, in pixels
        SDL_WINDOW_OPENGL        // flags - see below
        );

    // Check that the window was successfully created
    if (window == NULL)
    {
        // In the case that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return;
    }

    auto running = true;
    while(running) {
        
        SDL_Event event;
        while(SDL_PollEvent(&event)) {

            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}