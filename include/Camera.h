#ifndef CAMERA_H
#define CAMERA_H

#include "Transform.h"
#include "Matrix4.h"
#include "Rect.h"

class Camera {

public:
    Transform transform;

    enum ProjectionType {Orthographic, Perspective};

    Camera(ProjectionType type);
    const Matrix4& getProjection();
    const Matrix4& getView();
    void setViewportRect(const Rect& rect);
    const Rect& getViewportRect();
    void setNearPlane(float near);
    void setFarPlane(float far);
    
private:
    bool m_isDirty;
    Matrix4 m_projection;
    Matrix4 m_view;
    Rect m_rect;
    float m_near, m_far;
    ProjectionType m_projType;
};

#endif /*CAMERA_H*/
