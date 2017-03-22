

#ifndef RENDERER_LOCAL_INCLUDES_H
#define RENDERER_LOCAL_INCLUDES_H

#define OPENGL 1 // Use opengl on this project 
#define GL_GLEXT_PROTOTYPES 1



#if defined(__WIN32__) || defined(__WIN64__)
    #ifndef UNICODE
        #define UNICODE
    #endif

    #include <windows.h>    
    //#include <Winuser.h>
    //#include <Windowsx.h>

    // #pragma comment (lib, "opengl32.lib")
    // #pragma comment (lib, "gdi32.lib")
#else
    //#error "Not implemented yet"
#endif

#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"
//#include <GL/gl.h>
#include <map>
#include <memory>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <utility>
#include <string>

#endif /*RENDERER_LOCAL_INCLUDES_H*/