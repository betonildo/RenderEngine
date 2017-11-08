#ifndef CAMERA_H
#define CAMERA_H

#include "OSExport.h"
#include "components/Component.h"
#include "LinearMath.h"

class ENGINE_API Camera : public Component {

public:
    COMPONENT_OBJECT(Camera)

    enum class ProjectionType {
        Perspective, Orthographic
    };

    Camera();

    void setNearPlane(float nearPlane);
    void setFarPlane(float farPlane);
    void setFieldOfView(float fov);
    void setProjectionType(ProjectionType projType);
    const Matrix4& getProjectionMatrix() const;
    const Matrix4& getViewMatrix() const;

private:
    float mFieldOfView;
    float mNearPlane;
    float mFarPlane;
    mutable Matrix4 mProjectionMatrix;
    mutable bool mProjectionMatrixCachedValid;
    mutable Matrix4 mViewMatrix;
    ProjectionType mProjectionType;

};

#endif /*CAMERA_H*/