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

void Transform::setParent(Transform* parent) {
    // TODO: MAYBE RECALCULATE TRANSFORM OF CHILD
    mValidCalcCachedMatrix = false;
    mParent = parent;
    if (mParent != nullptr)
        mParent->addChild(this);
}

void Transform::addChild(Transform* child) {
    if (child != nullptr) mChildren.push_back(child);
}

void Transform::removeChild(Transform* child) {
    unsigned int childToRemoveIndex = -1;
    while (childToRemoveIndex + 1 < mChildren.size()) {
        childToRemoveIndex++;
        if (mChildren[childToRemoveIndex] == child) break;
    }

    if (childToRemoveIndex >= 0) {
        mChildren.erase(mChildren.begin() + childToRemoveIndex);
    }
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

const Matrix4& Transform::getWorldMatrix() const {
    if (!mValidCalcCachedMatrix) {
        // TODO: TAKE ACCOUNT OF PARENTAL FOR LOCAL CALCULATIONS
        // TODO: CALCULATE MODEL MATRIX USING POSITION, ROTATION AND SCALE
        Matrix4 T = Math::translate(Matrix4(1), mLocalPosition);
        Matrix4 S = Math::scale(mLocalScale);
        Matrix4 R = Math::mat4_cast(mLocalRotation);
        mWorldMatrix = T * R * S;
        mValidCalcCachedMatrix = true;
    }
    return mWorldMatrix;
}

const Transform* const Transform::getParent() const {
    return mParent;
}

Transform* Transform::getChildren() {
    return mChildren[0];
}

unsigned int Transform::getChildrenCount() {
    return (unsigned int)mChildren.size();
}

Vector3 Transform::getFront() const {
    return Vector3(mWorldMatrix[2]);
}

Vector3 Transform::getUp() const {
    return Vector3(mWorldMatrix[1]);
}

Vector3 Transform::getRight() const {
    return Vector3(mWorldMatrix[0]);
}