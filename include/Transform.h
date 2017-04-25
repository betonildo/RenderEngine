#include "renderer_local_includes.h"

#ifndef TRANSFORM_H
#define TRANSFORM_H

//TODO: Create the extract position, scale and rotation from model matrix to avoid storing it on this class

class Transform {

public:

    Transform();

    void setPosition(const glm::vec3& p);
    const glm::vec3& getPosition();

    void setScale(const glm::vec3& s);
    const glm::vec3& getScale();

    void setRotation(const glm::quat& r);
    const glm::quat& getRotation();
    
    glm::vec3 getFront();

    glm::mat4& getModelMatrix();
    
    inline bool isDirty() { return m_dirty; }

private:
    bool m_dirty;
    glm::mat4 m_modelMatrix;
    glm::vec3 m_position;
    glm::vec3 m_scale;
    glm::quat m_rotation;

};

#endif /*TRANSFORM_H*/