#ifndef DISPLAYDEVICE_H
#define DISPLAYDEVICE_H

class DisplayDevice {
public:
    
    virtual void start() = 0;
    virtual void setTitle(const char* title) = 0;
    virtual void setWidth(int width) = 0;
    virtual void setHeight(int height) = 0;
    virtual void swapBuffers() = 0;
    virtual bool isAvailable() = 0;
    virtual void pollEvents() = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual float getAspectRation() = 0;
};

#endif /*DISPLAYDEVICE_H*/