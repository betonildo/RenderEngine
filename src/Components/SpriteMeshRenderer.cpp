#include "Components/SpriteMeshRenderer.h"

SpriteMeshRenderer::SpriteMeshRenderer() {
    m_sprite.load("AOISJDOISD");
}

void SpriteMeshRenderer::start() {
    
}

void SpriteMeshRenderer::update() {
    
}

void SpriteMeshRenderer::end() {
    
}

void SpriteMeshRenderer::m_render(Camera* camera, Transform* transform) {
    Matrix4 M = transform->getModelMatrix();
    Matrix4 V = camera->getView();
    Matrix4 P = camera->getProjection();
    Matrix4 MVP = P * V * M;

    m_sprite.m_material.use();

    unsigned int MVPlocation = m_sprite.m_material.m_shader.getUniformLocation("MVP");
    m_sprite.m_material.m_shader.setMatrix4(MVPlocation, MVP);

    		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, m_sprite.m_vertexVBO);
		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
			);

		// 2nd attribute buffer : UVs
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, m_sprite.m_vertexVBO);
		glVertexAttribPointer(
			1,                                // attribute
			2,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			3,                                // stride
			(void*)0                          // array buffer offset
			);

		// 3rd attribute buffer : normals
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, m_sprite.m_vertexVBO);
		glVertexAttribPointer(
			2,                                // attribute
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			6,                                // stride
			(void*)0                          // array buffer offset
			);

		// Index buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_sprite.m_elementVBO);

		// Draw the triangles !
		glDrawElements(
			GL_TRIANGLES,        // mode
			m_sprite.m_indexes.size(),      // count
			GL_UNSIGNED_SHORT,   // type
			(void*)0             // element array buffer offset
			);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
}