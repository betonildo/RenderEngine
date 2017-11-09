#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"
#include "components/MeshRenderer.h"
#include "components/Camera.h"
#include "components/Light.h"
#include "assets/Mesh.h"
#include "assets/Material.h"
#include "scene/Actor.h"
#include "LinearMath.h"

MeshRenderer::MeshRenderer() {
    gl = GraphicLibrarySingleton::getInstance();
}

void MeshRenderer::setMesh(Mesh* mesh) {
    mMesh = mesh;
}

void MeshRenderer::addMaterial(Material* material) {
    mMaterials.push_back(material);
}

void MeshRenderer::render(const Camera* camera, const Light* lights, unsigned int lightCount) {
    Matrix4 M = mActor->transform.getModelMatrix();
    Matrix4 V = camera->getViewMatrix();
    Matrix4 P = camera->getProjectionMatrix();


    for (auto material : mMaterials) {
        material->bind();
        material->setUniform("ModelMatrix", M);
        material->setUniform("ViewMatrix", V);
        material->setUniform("ProjectionMatrix", P);
        gl->drawTriangles();
        material->unbind();
    }
}