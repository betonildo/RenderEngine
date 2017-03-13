#ifndef RENDERER_LOCAL_INCLUDES_H
#define RENDERER_LOCAL_INCLUDES_H

#include "SDL2/SDL.h"
#include <memory>
#include <vector>
#include <stdio.h>
#include <GL/gl.h>

#if defined(__WIN32__) || defined(__WIN64__)
    #ifndef UNICODE
        #define UNICODE
    #endif

    #include <windows.h>    
    #include <Winuser.h>
    #include <Windowsx.h>

    //#pragma comment (lib, "opengl32.lib")
#else
    //#error "Not implemented yet"
#endif

#endif /*RENDERER_LOCAL_INCLUDES_H*/