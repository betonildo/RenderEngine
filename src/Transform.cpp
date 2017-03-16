#include "Transform.h"

Transform::Transform() : m_modelMatrix(1.0) {
    
}

void Transform::setPosition(const Vector3& p) {
    m_dirty = true;
    m_position = p;
}

const Vector3& Transform::getPosition() {
    return m_position;
}

void Transform::setScale(const Vector3& s) {
    m_dirty = true;
    m_scale = s;
}

const Vector3& Transform::getScale() {
    return m_scale;
}

void Transform::setRotation(const Quaternion& r) {
    m_dirty = true;
    m_rotation = r;
}

const Quaternion& Transform::getRotation() {
    return m_rotation;
}

Vector3 Transform::getFront() {
    Vector4 front = m_rotation.v;
    Matrix4 rotation = m_rotation.getMatrix();
    front = front * rotation;
    return Vector3(front.x, front.y, front.z);
}


Matrix4& Transform::getModelMatrix() {
    if (m_dirty) {
        m_modelMatrix = m_rotation.getMatrix();
        m_modelMatrix.setTranslation(m_position);
        m_modelMatrix.setScale(m_scale);
    }

    return m_modelMatrix;
}

void Transform::concatenateTo(Transform& t1, Transform& t2, Transform& r) {
    r.setPosition(t1.getPosition() + t2.getPosition());
    //TODO: Discover if concatenation of scale is made by multiplication or addition
    r.setScale(t1.getScale() + t2.getScale());
    r.setRotation(t1.getRotation() * t2.getRotation());
}