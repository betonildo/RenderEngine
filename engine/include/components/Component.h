#ifndef COMPONENT_H
#define COMPONENT_H

#include "OSExport.h"
#include <memory>
#include <string>

#ifndef COMPONENT_NAME
    #define COMPONENT_NAME(COMPONENT_TYPE) #COMPONENT_TYPE
#endif

#define COMPONENT_OBJECT(COMPONENT_TYPE)                                                   \
    inline const char* getName() { return COMPONENT_NAME(COMPONENT_TYPE); }         \


class Actor;

class ENGINE_API Component {

public:
    Component();
    virtual void update(float dt);
    inline virtual const char* getName() = 0;
    void bindActor(std::shared_ptr<Actor> actor);

private:
    bool mActorBound = false;
    
protected:
    std::shared_ptr<Actor> mActor = nullptr;
};


#endif /*COMPONENT_H*/