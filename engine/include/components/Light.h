#ifndef LIGHT_H
#define LIGHT_H

#include "OSExport.h"
#include "components/Component.h"
#include "LinearMath.h"

class ENGINE_API Light : public Component {

public:

    COMPONENT_OBJECT(Light)
    
    float range;
    Color color;
    float intensity;
};

#endif /*LIGHT_H*/