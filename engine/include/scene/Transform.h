#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "OSExport.h"
#include "LinearMath.h"
#include <memory>

class ENGINE_API Transform {

public:
    Transform();
    ~Transform();

    void setLocalPosition(Vector3 localPosition);
    void setLocalRotation(Quaternion localRotation);
    void setLocalScale(Vector3 localScale);
    void setParent(std::shared_ptr<Transform> parent);

    const Vector3& getLocalPosition() const;
    const Quaternion& getLocalRotation() const;
    const Vector3& getLocalScale() const;
    const Matrix4& getModelMatrix() const;
    const std::shared_ptr<Transform> getParent() const;

    Vector3 getFront() const;
    Vector3 getUp() const;
    Vector3 getRight() const;

private:
    std::shared_ptr<Transform> mParent = nullptr;
    Vector3 mLocalPosition;
    Quaternion mLocalRotation;
    Vector3 mLocalScale;
    mutable Matrix4 mModelMatrix;
    mutable bool mValidCalcCachedMatrix;
};

#endif /*TRANSFORM_H*/