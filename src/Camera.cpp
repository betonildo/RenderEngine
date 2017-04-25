#include "Camera.h"

Camera::Camera(Camera::ProjectionType type) {
    m_projType = type;
    m_near = 0.01f;
    m_far = 1000.0f;
    m_isDirty = true;
}

const glm::mat4& Camera::getProjection() {
    // only setting viewport or near or far planes can dirty projection calculation
    if (m_isDirty) {
        // only Orthographic projection yet
        m_projection = glm::ortho (
            (float)(-m_rect.width/2.0 + m_rect.x),
            (float)(m_rect.width/2.0 + m_rect.x),
            (float)(-m_rect.height/2.0 + m_rect.y),
            (float)(m_rect.height/2.0 + m_rect.y),
            m_near,
            m_far
        );
    }

    return m_projection;
}

const glm::mat4& Camera::getView() {
    // if transform is dirty then the view matrix is dirty at all
    if (transform.isDirty()) {
        m_view = glm::lookAt(
            transform.getPosition(),                        // eye (place of transform)
            transform.getPosition() + transform.getFront(), // target (eye look direction)
            glm::vec3(0, 1, 0)                                // up vector 
        );
    }

    return m_view;
}

void Camera::setViewportRect(const Rect& rect) {
    m_isDirty = true;
    m_rect = rect;
}

const Rect& Camera::getViewportRect() {
    return m_rect;
}

void Camera::setNearPlane(float nearPlane) {
    m_isDirty = true;
    m_near = nearPlane;
}

void Camera::setFarPlane(float farPlane) {
    m_isDirty = true;
    m_far = farPlane;
}