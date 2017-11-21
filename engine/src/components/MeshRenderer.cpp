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

void MeshRenderer::render() {
    const Matrix4& M = mActor->transform.getWorldMatrix();

    for (auto material : mMaterials) {
		gl->pushBackObject();
		gl->pushMaterial(material);
		gl->pushMatrix4(GraphicLibrary::MatrixType::World, M);
		mMesh->drawTriangles();
    }
}