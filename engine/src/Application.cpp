#include "Application.h"
#include "device/DisplayDevice.h"
#include "device/WindowsDevice.h"
#include "scene/Scene.h"
#include "scene/EmptyScene.h"

Application::Application() {

}

Application::~Application() {
    delete mDevice;
    delete mScene;
}

void Application::start() {
    setScene(new EmptyScene());
    identifyOS();
    initializeDevice();
    mDevice->start();

    while(mDevice->isAvailable()) {
        mScene->update();
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

void Application::setScene(Scene* scene) {
    mScene = scene;
    mScene->start();
}