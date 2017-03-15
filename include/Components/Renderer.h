#ifndef RENDERER_H
#define RENDERER_H

#include "renderer_local_includes.h"
#include "Component.h"
#include "../RenderManager.h"
#include "../Camera.h"
#include "../Transform.h"
#include "../Assets/Material.h"

class RenderManager;
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
    virtual void m_render(Camera* camera, Transform* transform) = 0;

    friend class RenderManager;
};

#endif /*RENDERER_H*/