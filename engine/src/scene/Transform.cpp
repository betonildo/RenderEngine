#include "scene/Transform.h"

Vector3 FORWARD(0, 0, -1);

Transform::Transform() {
    mValidCalcCachedMatrix = false;
}

Transform::~Transform() {

}

void Transform::setLocalPosition(Vector3 localPosition) {
    mValidCalcCachedMatrix = false;
    mLocalPosition = localPosition;
}

void Transform::setLocalRotation(Quaternion localRotation) {
    mValidCalcCachedMatrix = false;
    mLocalRotation = localRotation;
}

void Transform::setLocalScale(Vector3 localScale) {
    mValidCalcCachedMatrix = false;
    mLocalScale = localScale;
}

void Transform::setParent(std::shared_ptr<Transform> parent) {
    // TODO: MAYBE RECALCULATE TRANSFORM OF CHILD
    mValidCalcCachedMatrix = false;
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
        // TODO: TAKE ACCOUNT OF PARENTAL FOR LOCAL CALCULATIONS
        // TODO: CALCULATE MODEL MATRIX USING POSITION, ROTATION AND SCALE
        Matrix4 T = Math::translate(Matrix4(1), mLocalPosition);
        Matrix4 S = Math::scale(mLocalScale);
        Matrix4 R = Math::mat4_cast(mLocalRotation);
        mModelMatrix = T * R * S;
        mValidCalcCachedMatrix = true;
    }
    return mModelMatrix;
}

const std::shared_ptr<Transform> Transform::getParent() const {
    return mParent;
}

Vector3 Transform::getFront() const {
    return Vector3(mModelMatrix[2]);
}

Vector3 Transform::getUp() const {
    return Vector3(mModelMatrix[1]);
}

Vector3 Transform::getRight() const {
    return Vector3(mModelMatrix[0]);
}