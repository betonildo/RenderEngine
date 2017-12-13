#include <GL/glew.h>
#include <SDL_opengl.h>
#include "components/Camera.h"
#include "components/Light.h"
#include "assets/Material.h"
#include "graphics/library/OpenGL/OpenGLRenderer.h"
#include "graphics/library/OpenGL/OpenGLErrorHandling.h"
#include "utils/FileUtils.h"

OpenGLRenderer::OpenGLRenderer() {

}

void OpenGLRenderer::pushMaterial(const Material* material) {
    mCurrentBoundObject.material = (Material*) material;
}

void OpenGLRenderer::pushLights(const Light* lights, uint lightCount) {
    mCurrentLights = lights;
    mCurrentLightsCount = lightCount;
}

void OpenGLRenderer::pushCamera(const Camera* camera) {
    pushMatrix4(MatrixType::Projection, camera->getProjectionMatrix());
    pushMatrix4(MatrixType::View, camera->getViewMatrix());
}

void OpenGLRenderer::pushMatrix4(MatrixType type, const Matrix4& m) {
    switch(type) {
        case MatrixType::World:
            mCurrentBoundObject.world = m;
            break;

        default:
            mMatrixCache[(unsigned int)type] = m;
            break;
    }
}

void OpenGLRenderer::pushAttributeValue(AttributeType type, const void* v, uint count) {

}

void OpenGLRenderer::setVector3(uint uniformLocation, const Vector3& v) {
    GLCall(glUniform3fv(uniformLocation, 3, Math::value_ptr(v)));
}

void OpenGLRenderer::setVector2(uint uniformLocation, const Vector2& v) {
    GLCall(glUniform2fv(uniformLocation, 3, Math::value_ptr(v)));
}

void OpenGLRenderer::setMatrix4(uint uniformLocation, const Matrix4& m) {
    GLCall(glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, Math::value_ptr(m)));
}

unsigned int OpenGLRenderer::getUniformLocation(const char* uniformName) {
    GLCall(uint uniformLocation = glGetUniformLocation(mCurrentBoundObject.shader, uniformName));
    return uniformLocation;
}

unsigned int OpenGLRenderer::getAttributeLocation(const char* attributeName) {
    GLCall(uint attributeLocation = glGetAttribLocation(mCurrentBoundObject.shader, attributeName));
    return attributeLocation;
}

void OpenGLRenderer::enableAttribute(unsigned int attributeLocation) {
    GLCall(glEnableVertexAttribArray(attributeLocation));
}

void OpenGLRenderer::disableAttribute(unsigned int attributeLocation) {
    GLCall(glDisableVertexAttribArray(attributeLocation));
}

unsigned int OpenGLRenderer::createShaderProgram(Shader* shaderSource) {
    //TODO: GLSL shader interpretation of source

	
}

unsigned int OpenGLRenderer::generateVertexBuffer() {
    uint vertexBufferObject;
    GLCall(glGenBuffers(1, &vertexBufferObject));

    VertexBuffer vbo;
    vbo.vbo = vertexBufferObject;
    vbo.location = 0; // Don't have this at this point
    vbo.format = {}; // Same from the last line
    mVertexBuffers.push_back(vbo);

    return mVertexBuffers.size() - 1;
}

unsigned int OpenGLRenderer::generateIndexBuffer() {
    uint indexBufferObject;
    GLCall(glGenBuffers(1, &indexBufferObject));

    IndexBuffer ibo;
    ibo.ibo = indexBufferObject;
    ibo.format = {}; // Don't have this at this point
    mIndexBuffers.push_back(ibo);
    return mIndexBuffers.size() - 1;
}

uint OpenGLRenderer::generateTextureBuffer() {
    uint textureLocation;
    GLCall(glGenTextures(1, &textureLocation));
    return textureLocation;
}

void OpenGLRenderer::bindTexture(uint textureLocation) {
    GLCall(glBindTexture(GL_TEXTURE_2D, textureLocation));
}

void OpenGLRenderer::bindTextureData(byte* data, TextureFormat format) {
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, format.width, format.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
    GLCall(glGenerateMipmap(GL_TEXTURE_2D));

}

void OpenGLRenderer::unbindTexture(uint textureLocation) {
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

void OpenGLRenderer::activeTexture(uint textureIndex) {
    GLCall(glActiveTexture(GL_TEXTURE0 + textureIndex));
}

void OpenGLRenderer::deactiveTexture(uint textureIndex) {
    GLCall(glActiveTexture(0));
}

ShaderProgram* OpenGLRenderer::getShaderProgram(unsigned int shaderProgramLocation) {
    return &mShaderPrograms[shaderProgramLocation];
}

void OpenGLRenderer::bindShaderProgram(unsigned int shaderProgramLocation) {
    mCurrentBoundObject.shader = shaderProgramLocation;
    GLCall(glUseProgram(mCurrentBoundObject.shader));
}

void OpenGLRenderer::unbindShaderProgram(unsigned int shaderProgramLocation) {
    mCurrentBoundObject.shader = 0;
    GLCall(glUseProgram(0));
}

void OpenGLRenderer::bindVertexBuffer(uint bufferLocation) {
    mCurrentBoundVertexBuffer = &mVertexBuffers[bufferLocation];
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, mCurrentBoundVertexBuffer->vbo));
    mCurrentBoundObject.vertexbuffers[mCurrentBoundObject.vertexbufferCount] = mCurrentBoundVertexBuffer;
    mCurrentBoundObject.vertexbufferCount++;
}

void OpenGLRenderer::bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector3> data) {
    GLCall(glBufferData(GL_ARRAY_BUFFER, data.size() * vertexFormat.getElementSize(), Math::value_ptr(data), GL_STATIC_DRAW));
    mCurrentBoundVertexBuffer->format = vertexFormat;
}

void OpenGLRenderer::bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector2> data) {
    GLCall(glBufferData(GL_ARRAY_BUFFER, data.size() * vertexFormat.getElementSize(), Math::value_ptr(data), GL_STATIC_DRAW));
    mCurrentBoundVertexBuffer->format = vertexFormat;
}

void OpenGLRenderer::bindVertexBufferData(VertexFormat vertexFormat, void* data, uint length) {
	// pushAttributeValue(vertexFormat.type, (const void*)data, length);
	GLCall(glBufferData(GL_ARRAY_BUFFER, length * vertexFormat.getElementSize(), data, GL_STATIC_DRAW));
	mCurrentBoundVertexBuffer->format = vertexFormat;
}

void OpenGLRenderer::unbindVertexBuffer(uint bufferLocation) {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void OpenGLRenderer::bindIndexBuffer(uint bufferLocation) {
    mCurrentBoundIndexBuffer = &mIndexBuffers[bufferLocation];
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mCurrentBoundIndexBuffer->ibo));
    mCurrentBoundObject.indexbuffer = mCurrentBoundIndexBuffer;
}

void OpenGLRenderer::bindIndexBufferData(ElementFormat elementFormat, std::vector<unsigned int> data) {
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementFormat.getSize(), Math::value_ptr(data), GL_STATIC_DRAW));
    mCurrentBoundIndexBuffer->format = elementFormat;
    mCurrentBoundIndexBuffer->elementsPointer = (void*)Math::value_ptr(data);
}

void OpenGLRenderer::unbindIndexBuffer(uint bufferLocation) {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void OpenGLRenderer::pushBackObject() {
    mCurrentBoundObject = {};
}

void OpenGLRenderer::clearObjectList() {
    mCurrentObjectsList.clear();
}

void OpenGLRenderer::drawElements() {
    mCurrentObjectsList.push_back(mCurrentBoundObject);
}

void OpenGLRenderer::processObjectList() {
    for(Object& object : mCurrentObjectsList) {
        object.material->bind();

        for (uint i = 0; i < object.vertexbufferCount; i++) {
            VertexFormat format = object.vertexbuffers[i]->format;

            // do opengl stuff
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, object.vertexbuffers[i]->vbo));
            GLCall(glEnableVertexAttribArray(format.attributeLocation));
            glVertexAttribPointer(
                format.attributeLocation,
                format.attributeCount,
                GetFormatTypeSizeInBytes(format.attributeType),
                format.normalized ? GL_TRUE : GL_FALSE,
                format.stride,
                (void*)format.offsetFirst
            );
        }

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object.indexbuffer->ibo);

        glDrawElements(
            ElementDrawModeToOpenGLMode(object.indexbuffer->format), 
            object.indexbuffer->format.count,
            GetFormatTypeSizeInBytes(object.indexbuffer->format.type),
            object.indexbuffer->elementsPointer
        );

        object.material->unbind();
    }
}

void OpenGLRenderer::init() {
	
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        //NOT OK
    }

    mBackBufferData.clear();
    mViewport = {};
}

void OpenGLRenderer::setViewportRect(Rect rect) {
    mViewport = rect;
    mBackBufferData.resize(rect.width * rect.height);
    glViewport(rect.x, rect.y, rect.width, rect.height);
}

void* OpenGLRenderer::getBackBuffer() {
    glReadPixels(
        mViewport.x, 
        mViewport.y, 
        mViewport.width, 
        mViewport.height, 
        GL_RGBA, 
        GL_UNSIGNED_BYTE, 
        &mBackBufferData[0]
    );
    return mBackBufferData.data();
}

uint OpenGLRenderer::ElementDrawModeToOpenGLMode(const ElementFormat& format) {
    		switch(format.mode) {
			case ElementFormat::Mode::Points:
				return GL_POINTS;
				break;

			case ElementFormat::Mode::LineStrip:
				return GL_LINE_STRIP;
				break;

			case ElementFormat::Mode::LineLoop:
				return GL_LINE_LOOP;
				break;

			case ElementFormat::Mode::Lines:
				return GL_LINES;
				break;

			case ElementFormat::Mode::LineStripAdjacency:
				return GL_LINE_STRIP_ADJACENCY;
				break;

			case ElementFormat::Mode::LinesAdjacency:
				return GL_LINES_ADJACENCY;
				break;

			case ElementFormat::Mode::TriangleStrip:
				return GL_TRIANGLE_STRIP;
				break;

			case ElementFormat::Mode::TriangleFan:
				return GL_TRIANGLE_FAN;
				break;

			case ElementFormat::Mode::Triangles:
				return GL_TRIANGLES;
				break;

			case ElementFormat::Mode::TriangleStripAdjacency:
				return GL_TRIANGLE_STRIP_ADJACENCY;
				break;

			case ElementFormat::Mode::TrianglesAdjacency:
				return GL_TRIANGLES_ADJACENCY;
				break;
			
			default:
				return GL_TRIANGLES;
				break;
		}
}