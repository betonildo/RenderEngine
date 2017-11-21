#ifndef COMPONENT_H
#define COMPONENT_H

#include "OSExport.h"
#include <memory>
#include <string>

class Transform;

#ifndef COMPONENT_NAME
    #define COMPONENT_NAME(COMPONENT_TYPE) #COMPONENT_TYPE
#endif

#ifndef COMPONENT_OBJECT
    #define COMPONENT_OBJECT(COMPONENT_TYPE)                                             \
        inline virtual const char* getName() { return COMPONENT_NAME(COMPONENT_TYPE); }  \

#endif

class Actor;

class ENGINE_API Component {

public:
    Component();

    COMPONENT_OBJECT(Component)

    virtual void update(float dt);
    void bindActor(std::shared_ptr<Actor> actor);
    Transform& getTransform() const;

private:
    bool mActorBound = false;
    
protected:
    std::shared_ptr<Actor> mActor = nullptr;
};


#endif /*COMPONENT_H*/