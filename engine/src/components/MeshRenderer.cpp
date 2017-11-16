#include "graphics/GraphicLibrarySingleton.h"
#include "graphics/GraphicLibrary.h"
#include "graphics/VertexFormat.h"
#include "graphics/Vertex.h"
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
	unsigned int pBuffer = gl->generateVertexBuffer();
	unsigned int nBuffer = gl->generateVertexBuffer();
	unsigned int uvBuffer = gl->generateVertexBuffer();
	unsigned int eBuffer = gl->generateElementBuffer();

	mMesh->setPositionBuffer(gl->getVertexBuffer(pBuffer));
	mMesh->setNormalBuffer(gl->getVertexBuffer(nBuffer));
	mMesh->setUVBuffer(gl->getVertexBuffer(uvBuffer));
	mMesh->setIndexBuffer(gl->getElementBuffer(eBuffer));
}

void MeshRenderer::addMaterial(Material* material) {
    mMaterials.push_back(material);
}

void MeshRenderer::render(const Camera* camera, const Light* lights, unsigned int lightCount) {
    Matrix4 M = mActor->transform.getModelMatrix();
    Matrix4 V = camera->getViewMatrix();
    Matrix4 P = camera->getProjectionMatrix();

    for (auto material : mMaterials) {
		gl->pushBackCommand();
        material->bind();
        material->setUniform("ModelMatrix", M);
        material->setUniform("ViewMatrix", V);
        material->setUniform("ProjectionMatrix", P);

		mMesh->bind();
		mMesh->drawTriangles();
		mMesh->unbind();
        material->unbind();
    }
}