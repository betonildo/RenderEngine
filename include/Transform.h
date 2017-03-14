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

    void setRotation(const Quaternion& r);
    Quaternion getRotation();
    
    Matrix4& getModelMatrix();

    static void concatenateTo(Transform& t1, Transform& t2, Transform& r);

private:
    bool m_dirty;
    Matrix4 m_modelMatrix;

    Vector3 m_position;
    Vector3 m_scale;
    Quaternion m_rotation;

};

#endif /*TRANSFORM_H*/