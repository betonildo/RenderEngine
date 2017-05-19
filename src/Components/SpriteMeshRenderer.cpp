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

void SpriteMeshRenderer::m_render(Camera* camera, glm::mat4& concatenatedMatrix) {
    
	glm::mat4 M = concatenatedMatrix;
    glm::mat4 V = camera->getView();
    glm::mat4 P = camera->getProjection();
    glm::mat4 MVP = P * V * M;
	

	// check_gl_error();

    m_sprite.m_material.m_shader.use();

	unsigned int MVPlocation = m_sprite.m_material.m_shader.getUniformLocation("MVP");
    m_sprite.m_material.m_shader.setMatrix4(MVPlocation, MVP);

	// Specify the layout of the vertex data
    unsigned int positionLocation = m_sprite.m_material.m_shader.getAttributeLocation("position");
	unsigned int normalLocation = m_sprite.m_material.m_shader.getAttributeLocation("normal");
	unsigned int uvLocation = m_sprite.m_material.m_shader.getAttributeLocation("uv");

	
	Texture t = m_sprite.m_material.getTexture("spriteTexture");
	int unid = m_sprite.m_material.m_shader.getUniformLocation("spriteTexture");
	m_sprite.m_material.m_shader.setTexture(unid, t);
	
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(positionLocation);
	glBindBuffer(GL_ARRAY_BUFFER, m_sprite.m_vertexVBO);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);

	// 2nd attribute buffer : NORMAL
	glEnableVertexAttribArray(normalLocation);
	glBindBuffer(GL_ARRAY_BUFFER, m_sprite.m_normalVBO);
	glVertexAttribPointer(
		1,                                // attribute
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);

	// 3rd attribute buffer : normals
	glEnableVertexAttribArray(uvLocation);
	glBindBuffer(GL_ARRAY_BUFFER, m_sprite.m_uvVBO);
	glVertexAttribPointer(
		2,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);
 //set size to 5 for another group of points
//  glPointSize(5);  
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