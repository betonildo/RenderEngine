#ifndef EMPTYSCENE_H
#define EMPTYSCENE_H

#include "scene/Scene.h"

class EmptyScene: public Scene {

public:
    EmptyScene();
    ~EmptyScene();
    void start();
    void update();
};

#endif /*EMPTYSCENE_H*/