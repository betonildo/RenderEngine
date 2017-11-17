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
    const Matrix4& M = mActor->transform.getWorldMatrix();
    const Matrix4& V = camera->getViewMatrix();
    const Matrix4& P = camera->getProjectionMatrix();
	
    for (auto material : mMaterials) {
		gl->pushBackCommand();
		gl->pushMaterial(material);
		gl->pushLights(lights, lightCount);
		gl->pushMatrix4(GraphicLibrary::MatrixType::World, M);
		gl->pushMatrix4(GraphicLibrary::MatrixType::View, V);
		gl->pushMatrix4(GraphicLibrary::MatrixType::Projection, P);
		mMesh->drawTriangles();
    }
}