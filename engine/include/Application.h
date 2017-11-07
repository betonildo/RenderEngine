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
    enum class OSType {
        Windows, Android
    };
    
    bool mSceneHasChanged;
    DisplayDevice* mDevice;
    Scene* mScene;
    OSType mOSType;

    void identifyOS();
    void initializeDevice();
    void changeScene();
};

#endif /*APPLICATION_H*/