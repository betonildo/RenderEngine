#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4.h"

struct Vector3;
class Quaternion;
class Matrix4;

//TODO: Create the extract position, scale and rotation from model matrix to avoid storing it on this class

class Transform {

public:

    Transform();

    void setPosition(const Vector3& p);
    const Vector3& getPosition();

    void setScale(const Vector3& s);
    const Vector3& getScale();

    void setRotation(const Quaternion& r);
    const Quaternion& getRotation();
    
    Vector3 getFront();

    Matrix4& getModelMatrix();
    
    inline bool isDirty() { return m_dirty; }

private:
    bool m_dirty;
    Matrix4 m_modelMatrix;
    Vector3 m_position;
    Vector3 m_scale;
    Quaternion m_rotation;

};

#endif /*TRANSFORM_H*/