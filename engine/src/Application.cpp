#include "Application.h"
#include "device/DisplayDevice.h"
#include "device/WindowsDevice.h"
#include "scene/Scene.h"
#include "scene/EmptyScene.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/RayTracer.h"

Application::Application() {
    mSceneHasChanged = true;
}

Application::~Application() {
    delete mDevice;
    delete mScene;
}

void Application::start() {
    // TODO: REORGANIZE THIS TO A METHOD AND TO SELECT PROPERLY THE GRAPHICS LIBRARY
    GraphicLibrarySingleton::setInstance<RayTracer>();
    
    identifyOS();
    initializeDevice();

	GraphicLibrarySingleton::getInstance()->init();

    if (mScene == nullptr)
        setScene(new EmptyScene());
    mDevice->start();

    while(mDevice->isAvailable()) {
        if (mSceneHasChanged) changeScene();
        mScene->update();
        mScene->render();
        mDevice->swapBuffers();
        mDevice->pollEvents();
    }
}

void Application::identifyOS() {
    // TODO: discover OS (maybe with macros)
    mOSType = OSType::Windows;
}

void Application::initializeDevice() {
    switch(mOSType) {
        case OSType::Windows:
            mDevice = new WindowsDevice();
            break;
    }

    // TODO: Get from external config source
    mDevice->setTitle("Application");
    mDevice->setWidth(640);
    mDevice->setHeight(480);
}

void Application::changeScene() {
    mScene->preStart();
    mScene->start();
    mSceneHasChanged = false;
}

void Application::setScene(Scene* scene) {
    mScene = scene;
    mSceneHasChanged = true;
}