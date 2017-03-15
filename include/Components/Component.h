#ifndef COMPONENT_H
#define COMPONENT_H

#include "../SceneObject.h"

class SceneObject;

class Component {

public:
    

protected:

    virtual ~Component() { }

    virtual void start() = 0;
    virtual void update() = 0;
    virtual void end() = 0;

    inline SceneObject* getSceneObject() { return m_sceneObject; }

private:

    SceneObject* m_sceneObject;

    friend class SceneObject;
};

#endif /*COMPONENT_H*/