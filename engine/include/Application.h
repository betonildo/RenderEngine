#ifndef APPLICATION_H
#define APPLICATION_H

#include "OSExport.h"

class DisplayDevice;
class Scene;

class ENGINE_API Application {

public:
    Application();
    ~Application();
    void start();
    void setScene(Scene* scene);

private:
    DisplayDevice* mDevice;
    Scene* mScene;

    enum class OSType {
        Windows, Android
    };

    OSType mOSType;

    void identifyOS();
    void initializeDevice();
};

#endif /*APPLICATION_H*/