#ifndef SCENE_H
#define SCENE_H

#include "renderer_local_includes.h"

class Scene {

public:
    void render();
    void addChild(SceneObject* sceneObject);

    virtual void start() = 0;
    virtual void end() = 0;

private:
    std::vector< std::unique_ptr<sceneObject> > m_children;
    void m_cleanUp();

};

#endif /*SCENE_H*/
