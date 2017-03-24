#include "Transform.h"

Transform::Transform() {
    m_dirty = true;
    m_modelMatrix.turnIdentity();
    m_position.x = 0;
    m_position.y = 0;
    m_position.z = 0;
    m_scale.x = 1;
    m_scale.y = 1;
    m_scale.z = 1;
    m_rotation.v.x = 0;
    m_rotation.v.y = 0;
    m_rotation.v.y = 0;
    m_rotation.s = 0;
}

void Transform::setPosition(const Vector3& p) {
    m_dirty = true;
    m_position = p;
}

Vector3& Transform::getPosition() {
    return m_position;
}

void Transform::setScale(const Vector3& s) {
    m_dirty = true;
    m_scale = s;
}

Vector3& Transform::getScale() {
    return m_scale;
}

void Transform::setRotation(const Quaternion& r) {
    m_dirty = true;
    m_rotation = r;
}

Quaternion& Transform::getRotation() {
    return m_rotation;
}

Vector3 Transform::getFront() {
    Vector4 front(0, 0, -1, 1);
    Matrix4 rotation = Matrix4::Rotation(m_rotation);
    front = front * rotation;
    return Vector3(front.x, front.y, front.z);
}


Matrix4& Transform::getModelMatrix() {
    if (m_dirty) {
        m_modelMatrix.turnIdentity();
        Matrix4 r = Matrix4::Rotation(m_rotation);
        Matrix4 t = Matrix4::Translation(m_position);
        Matrix4 s = Matrix4::Scale(m_scale);
        m_dirty = false;

        m_modelMatrix = t * r * s;
    }

    return m_modelMatrix;
}