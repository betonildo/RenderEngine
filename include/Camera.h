#ifndef CAMERA_H
#define CAMERA_H

#include "Transform.h"
#include "Matrix4.h"
#include "Rect.h"

class Camera {

public:
    Transform transform;

    enum {Orthographic, Perspective};

    const Matrix4& getProjection() = 0;
    const Matrix4& getView() = 0;
    void setViewportRect(const Rect& rect);
    const Rect& getViewportRect();

private:
    bool dirty;
    Matrix4 m_projection;
    Matrix4 m_view;
    Rect m_rect;

};

#endif /*CAMERA_H*/
