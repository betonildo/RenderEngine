#include "components/Camera.h"
#include "scene/Actor.h"

Camera::Camera() {
    mProjectionMatrixCachedValid = false;
}


void Camera::setNearPlane(float nearPlane) {
    mNearPlane = nearPlane;
    mProjectionMatrixCachedValid = false;
}

void Camera::setFarPlane(float farPlane) {
    mFarPlane = farPlane;
    mProjectionMatrixCachedValid = false;
}

void Camera::setFieldOfView(float fov) {
    mFieldOfView = fov;
    mProjectionMatrixCachedValid = false;
}

float Camera::getFieldOfView() const {
    return mFieldOfView;
}

void Camera::setProjectionType(ProjectionType projType) {
    mProjectionType = projType;
    mProjectionMatrixCachedValid = false;
}

const Matrix4& Camera::getProjectionMatrix() const {
    if (!mProjectionMatrixCachedValid) {
        switch(mProjectionType) {
            case ProjectionType::Orthographic: {
                // TODO: CALCULATE ORTHOGRAPHIC CORRECTLY
                break;
            }
    
            case ProjectionType::Perspective: {
                mProjectionMatrix = Math::perspective(
                    mFieldOfView,
                    4.0f/3.0f, // TODO: GET WINDOW ASPECT RATIO
                    mNearPlane,
                    mFarPlane
                );
                break;
            }
    
            default:
                break;
        }
    }

    return mProjectionMatrix;
}

const Matrix4& Camera::getViewMatrix() const {
    // TODO: TRY TO CACHE THIS CALCULATION
    const Vector3 position = mActor->transform.getLocalPosition();
    const Vector3 front = mActor->transform.getFront();
    const Vector3 target = position + front;
    mViewMatrix = Math::lookAt(
        position,
        position + target,
        Vector3(0, 1, 0)
    );
    return mViewMatrix;
}