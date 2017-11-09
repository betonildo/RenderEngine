#ifndef WINDOWSDEVICE_H
#define WINDOWSDEVICE_H

#include "OSExport.h"
#include "device/DisplayDevice.h"

class GraphicLibrary;
struct SDL_Window;
struct SDL_Texture;
struct SDL_Renderer;

class WindowsDevice : public DisplayDevice {

public:

    WindowsDevice();
    ~WindowsDevice();

    void start();
    void setTitle(const char* title);
    void setWidth(int width);
    void setHeight(int height);
    void swapBuffers();
    bool isAvailable();
    void pollEvents();
    int getWidth();
    int getHeight();
    float getAspectRation();

private:
	GraphicLibrary* gl;
    char* mTitle;    
    SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	SDL_Texture* mTargetTexture;

    int mWidth;
    int mHeight;
    bool mNoQuit = false;

    void initSDL2();
};

#endif /*WINDOWSDEVICE_H*/