#include "renderer_local_includes.h"
#include "../Assets/Sprite.h"
#include "Renderer.h"

#ifndef SPRITEMESHRENDERER_H
#define SPRITEMESHRENDERER_H

class Sprite;
class Renderer;

class SpriteMeshRenderer : public Renderer {

public:
    SpriteMeshRenderer();
    virtual void start();
    virtual void update();
    virtual void end();

protected:
    virtual void m_render(Camera* camera, glm::mat4& concatenatedMatrix);

private:
    Sprite m_sprite;
};

#endif /**/