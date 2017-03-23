#include "Transform.h"

Transform::Transform() {
    m_modelMatrix.turnIdentity();
    m_position.x = 0;
    m_position.y = 0;
    m_position.z = 0;
    m_scale.x = 0;
    m_scale.y = 0;
    m_scale.z = 0;
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
    Vector4 front(m_rotation.v.x, m_rotation.v.y, m_rotation.v.z, 1);
    Matrix4 rotation = m_rotation.getMatrix();
    front = front * rotation;
    return Vector3(front.x, front.y, front.z);
}


const Matrix4& Transform::getModelMatrix() {
    if (m_dirty) {
        //m_modelMatrix = m_rotation.getMatrix();
        m_modelMatrix.setTranslation(m_position);
        //m_modelMatrix.setScale(m_scale);
    }

    return m_modelMatrix;
}