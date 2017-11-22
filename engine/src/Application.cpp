#include "Application.h"
#include "assets/Resources.h"
#include "loaders/TextureLoader.h"
#include "loaders/SoilTextureLoader.h"
#include "device/DisplayDevice.h"
#include "device/WindowsDevice.h"
#include "scene/Scene.h"
#include "scene/EmptyScene.h"
#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/RayTracer.h"
#include <thread>
#include <iostream>

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
    Resources::setTextureLoaderInstance<SoilTextureLoader>();
    identifyOS();
    initializeDevice();

	GraphicLibrarySingleton::getInstance()->init();

    if (mScene == nullptr)
        setScene(new EmptyScene());
    mDevice->start();

    std::thread t([&]() {
        std::cout << "Running thread..." << std::endl;
        while(mDevice->isAvailable()) {
            if (mSceneHasChanged) changeScene();
            mScene->update();
            mScene->render();
        }
    });

    while(mDevice->isAvailable()) {
        mDevice->swapBuffers();
        mDevice->pollEvents();
    }

    t.join();
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