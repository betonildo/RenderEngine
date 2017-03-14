#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4.h"

class Transform {

public:

    void setPosition(const Vector3& p);
    Vector3 getPosition();

    void setScale(const Vector3& s);
    Vector3 getScale();

    void setQuaternion(const Quaternion& r);
    Quaternion getQuaternion();
    
    Matrix4& getModelMatrix();

private:
    bool m_dirty;
    Matrix4 m_modelMatrix;

    Vector3 m_position;
    Vector3 m_scale;
    Quaternion m_quaternion;

};

#endif /*TRANSFORM_H*/