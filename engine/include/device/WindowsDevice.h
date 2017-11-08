#ifndef WINDOWSDEVICE_H
#define WINDOWSDEVICE_H

#include "OSExport.h"
#include "device/DisplayDevice.h"

struct SDL_Window;

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
    char* mTitle;
    
    SDL_Window* mWindow;

    int mWidth;
    int mHeight;
    bool mNoQuit = false;

    void initSDL2();
    void initGlew();
};

#endif /*WINDOWSDEVICE_H*/