#include "renderer_local_includes.h"
#include "Component.h"
#include "../Camera.h"
#include "../Transform.h"
#include "../Assets/Material.h"

#ifndef RENDERER_H
#define RENDERER_H

class Camera;
class Transform;
class Material;

class Renderer : public Component {

public:    
    inline void setMaterial(Material* m) {
        m_material = m;
    }

protected:
    Material* m_material;
    virtual void m_render(Camera* camera, glm::mat4& concatenatedMatrix) = 0;

    friend class RenderManager;
};

#endif /*RENDERER_H*/