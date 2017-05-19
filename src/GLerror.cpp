#include "renderer_local_includes.h"
#include "GLerror.h"
 
using namespace std;

map<pair<string, int>, pair<string, int> > error_map;

void _check_gl_error(const char *file, int line) {
        GLenum err (glGetError());
 
        while(err!=GL_NO_ERROR) {
                string error;
 
                switch(err) {
                        case GL_INVALID_OPERATION:      error="INVALID_OPERATION";      break;
                        case GL_INVALID_ENUM:           error="INVALID_ENUM";           break;
                        case GL_INVALID_VALUE:          error="INVALID_VALUE";          break;
                        case GL_OUT_OF_MEMORY:          error="OUT_OF_MEMORY";          break;
                        case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
                }
 
                pair<string, int> key(error, err);
                pair<string, int> value(string(file), line);

                if (error_map.find(key) != error_map.end()) {
                        std::cout << "Already passed an error on these lines:" << std::endl;
                        std::cout << "Error: " << error << std::endl;
                        std::cout << "Error Code: " << err << std::endl;
                        std::cout << "File: " << file << std::endl;
                        std::cout << "Line: " << line << std::endl;
                        exit(-1);
                }
                cerr << "GL_" << error.c_str() <<" - "<<file<<":"<<line<<endl;
                err=glGetError();
                error_map[key] = value;
        }
}