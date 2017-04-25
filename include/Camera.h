#ifndef CAMERA_H
#define CAMERA_H

#include "renderer_local_includes.h"
#include "Transform.h"
#include "Rect.h"

class Camera {

public:
    Transform transform;

    enum ProjectionType {Orthographic, Perspective};

    Camera(ProjectionType type);
    const glm::mat4& getProjection();
    const glm::mat4& getView();
    void setViewportRect(const Rect& rect);
    const Rect& getViewportRect();
    void setNearPlane(float nearPlane);
    void setFarPlane(float farPlane);
    
private:
    bool m_isDirty;
    glm::mat4 m_projection;
    glm::mat4 m_view;
    Rect m_rect;
    float m_near, m_far;
    ProjectionType m_projType;
};

#endif /*CAMERA_H*/
