#include "Transform.h"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include "glm/ext.hpp" 
#include "glm/gtx/string_cast.hpp"

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
    Vector4 front(0, 0, -1, 1);
    Matrix4 rotation = Matrix4::Rotation(m_rotation);
    front = front * rotation;
    return Vector3(front.x, front.y, front.z);
}


Matrix4& Transform::getModelMatrix() {
    if (m_dirty) {
        m_dirty = false;

        m_modelMatrix.turnIdentity();
        Matrix4 r = Matrix4::Rotation(m_rotation);
        Matrix4 t = Matrix4::Translation(m_position);
        Matrix4 s = Matrix4::Scale(m_scale);
        
        m_modelMatrix = t * r * s;
    }

    return m_modelMatrix;
}