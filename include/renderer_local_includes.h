

#ifndef RENDERER_LOCAL_INCLUDES_H
#define RENDERER_LOCAL_INCLUDES_H

#define OPENGL 1 // Use opengl on this project 
#define GL_GLEXT_PROTOTYPES 1

#define PI 3.1415

// Converts degrees to radians.
#define ToRadians(angleDegrees) ((angleDegrees) * PI / 180.0)

// Converts radians to degrees.
#define ToDegrees(angleRadians) ((angleRadians) * 180.0 / PI)

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
#include "SOIL.h"
//#include <GL/gl.h>
#include <map>
#include <memory>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <utility>
#include <fstream>
#include <string>
#include <iostream>

#include <glm/vec2.hpp> // glm::vec3
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/projection.hpp>
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/ext.hpp>

#include <glm/gtx/string_cast.hpp>

#endif /*RENDERER_LOCAL_INCLUDES_H*/