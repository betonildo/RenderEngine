#ifndef NULLCOMPONENT_H
#define NULLCOMPONENT_H

#include "components/Component.h"

class NullComponent : public Component {
    
public:

    NullComponent() {
        
    }

    COMPONENT_OBJECT(NullComponent);

    inline virtual void update(float dt) {

    }
};

#endif /*NULLCOMPONENT_H*/