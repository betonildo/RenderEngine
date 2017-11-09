#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include "OSExport.h"
#include "components/Renderer.h"
#include <vector>

class Mesh;
class Material;
class Camera;
class GraphicLibrary;

class ENGINE_API MeshRenderer : public Renderer {

public:
    MeshRenderer();

    void setMesh(Mesh* mesh);
    void addMaterial(Material* material);
    virtual void render(const Camera* camera, const Light* lights, unsigned int lightCount);

private:
    Mesh* mMesh;
    std::vector< Material* > mMaterials;
    GraphicLibrary* gl;
};

#endif /*MESHRENDERER_H*/