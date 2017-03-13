#ifndef CAMERA_H
#define CAMERA_H

// TODO: integrate with Math library
#include "Matrix4.h"

class Camera {

public:
    enum {
        Orthographic,
        Perspective
    };

    Matrix4& getProjection();
    

private:
    
};

#endif /*CAMERA_H*/
