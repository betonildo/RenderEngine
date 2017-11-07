#include "scene/Transform.h"

Transform::Transform() {
    mValidCalcCachedMatrix = false;
}

Transform::~Transform() {

}

void Transform::setLocalPosition(Vector3 localPosition) {
    mLocalPosition = localPosition;
}

void Transform::setLocalRotation(Quaternion localRotation) {
    mLocalRotation = localRotation;
}

void Transform::setLocalScale(Vector3 localScale) {
    mLocalScale = localScale;
}

void Transform::setParent(std::shared_ptr<Transform> parent) {
    // TODO: MAYBE RECALCULATE TRANSFORM OF CHILD
    mParent = parent;
}

const Vector3& Transform::getLocalPosition() const {
    return mLocalPosition;
}

const Quaternion& Transform::getLocalRotation() const {
    return mLocalRotation;
}

const Vector3& Transform::getLocalScale() const {
    return mLocalScale;
}

const Matrix4& Transform::getModelMatrix() const {
    if (!mValidCalcCachedMatrix) {
        // TODO: CALCULATE MODEL MATRIX USING POSITION, ROTATION AND SCALE
        mValidCalcCachedMatrix = true;
    }
    return mModelMatrix;
}

const std::shared_ptr<Transform> Transform::getParent() const {
    return mParent;
}