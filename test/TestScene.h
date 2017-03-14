#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "Scene.h"

class TestScene : public Scene {

public:
    inline virtual void start() {
        SceneObject* one = new SceneObject();
        addChild(one);
    }

    inline virtual void end() {

    }
};

#endif /*TESTSCENE_H*/