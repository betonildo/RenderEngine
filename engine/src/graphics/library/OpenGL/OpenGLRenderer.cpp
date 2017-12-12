#include "GL/glew.h"
#include "SDL2/SDL2_opengl.h"
#include "graphics/library/OpenGL/OpenGLRenderer.h"


OpenGLRenderer::OpenGLRenderer() {

}

void OpenGLRenderer::pushMaterial(const Material* material) {
    mCurrentBoundObject.material = material;
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
    mMatrixCache[(unsigned int)type] = m;
}

void OpenGLRenderer::pushAttributeValue(AttributeType type, const void* v, uint count) {

}

void OpenGLRenderer::setVector3(uint uniformLocation, const Vector3& v) {

}

void OpenGLRenderer::setVector2(uint uniformLocation, const Vector2& v) {

}

void OpenGLRenderer::setMatrix4(uint uniformLocation, const Matrix4& m) {

}

unsigned int OpenGLRenderer::getUniformLocation(const char* uniformName) {
    
}

unsigned int OpenGLRenderer::getAttributeLocation(const char* attributeName) {

}

void OpenGLRenderer::enableAttribute(unsigned int attributeLocation) {

}

void OpenGLRenderer::disableAttribute(unsigned int attributeLocation) {

}

unsigned int OpenGLRenderer::createShaderProgram(Shader* shaderSource) {

}

unsigned int OpenGLRenderer::generateVertexBuffer() {

}

unsigned int OpenGLRenderer::generateIndexBuffer() {

}

uint OpenGLRenderer::generateTextureBuffer() {

}

void OpenGLRenderer::bindTexture(uint textureLocation) {

}

void OpenGLRenderer::bindTextureData(byte* data, TextureFormat format) {

}

void OpenGLRenderer::unbindTexture(uint textureLocation) {

}

void OpenGLRenderer::activeTexture(uint textureIndex) {

}

void OpenGLRenderer::deactiveTexture(uint textureIndex) {

}

ShaderProgram* OpenGLRenderer::getShaderProgram(unsigned int shaderProgramLocation) {

}

void OpenGLRenderer::bindShaderProgram(unsigned int shaderProgramLocation) {

}

void OpenGLRenderer::unbindShaderProgram(unsigned int shaderProgramLocation) {

}

void OpenGLRenderer::bindVertexBuffer(uint bufferLocation) {

}

void OpenGLRenderer::bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector3> data) {

}

void OpenGLRenderer::bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector2> data) {

}

void OpenGLRenderer::unbindVertexBuffer(uint bufferLocation) {

}

void OpenGLRenderer::bindIndexBuffer(uint bufferLocation) {

}

void OpenGLRenderer::bindIndexBufferData(ElementFormat elementFormat, std::vector<unsigned int> data) {

}

void OpenGLRenderer::unbindIndexBuffer(uint bufferLocation) {

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


        // do opengl stuff

        object.material->unbind();
    }
}

void OpenGLRenderer::init() {
    SDL2_CreateContext();
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
        &mBackBuffer[0]
    );
    return mBackBufferData.data();
}