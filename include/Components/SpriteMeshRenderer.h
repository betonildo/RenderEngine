#include "Vector2.h"
#include "../Assets/Texture.h"
#include "../Assets/Shader.h"
#include "../Assets/Mesh.h"
#include "Renderer.h"

#ifndef SPRITEMESHRENDERER_H
#define SPRITEMESHRENDERER_H

class Texture;
class Shader;
class Renderer;
class Mesh;

class SpriteMeshRenderer : public Renderer {

public:
    SpriteMeshRenderer();
    virtual void start();
    virtual void update();
    virtual void end();

protected:
    virtual void m_render(Camera* camera, Transform* transform);

private:
    Shader m_shader;
    Texture m_texture;
    unsigned int m_vbo;
};

#endif /**/