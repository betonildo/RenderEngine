#include "Camera.h"

Camera::Camera(Camera::ProjectionType type) {
    m_projType = type;
    m_near = 0.01f;
    m_far = 1000.0f;
    m_isDirty = true;
}

const Matrix4& Camera::getProjection() {
    // only setting viewport or near or far planes can dirty projection calculation
    if (m_isDirty) {
        // only Orthographic projection yet
        m_projection = Matrix4::orthoProjection(
            -m_rect.width/2.0 + m_rect.x,
            m_rect.width/2.0 + m_rect.x,
            -m_rect.height/2.0 + m_rect.y,
            m_rect.height/2.0 + m_rect.y,
            m_near,
            m_far
        );
    }

    return m_projection;
}

const Matrix4& Camera::getView() {
    // if transform is dirty then the view matrix is dirty at all
    if (transform.isDirty()) {
        m_view = Matrix4::lookAt(
            transform.getPosition(),                        // eye (place of transform)
            transform.getPosition() + transform.getFront(), // target (eye look direction)
            Vector3(0, 1, 0)                                // up vector 
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

void Camera::setNearPlane(float near) {
    m_isDirty = true;
    m_near = near;
}

void Camera::setFarPlane(float far) {
    m_isDirty = true;
    m_far = far;
}