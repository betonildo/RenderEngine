#ifndef SCENE_H
#define SCENE_H


#include "OSEXport.h"
#include <vector>

class Actor;

class ENGINE_API Scene {

public:
    Scene();
    ~Scene();
    virtual void start() = 0;
    virtual void update() = 0;
    void add(Actor* actor);
    
private:
    void render();
    std::vector<Actor*> mActors;

};

#endif /*SCENE_H*/