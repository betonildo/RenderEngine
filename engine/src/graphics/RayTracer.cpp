#include "graphics/RayTracer.h"
#include "graphics/TextureFormat.h"
#include "graphics/VertexFormat.h"
#include "graphics/ElementFormat.h"
#include "graphics/ShaderProgram.h"
#include "graphics/RaycastHit.h"
#include "components/Camera.h"
#include "components/Light.h"
#include "scene/Transform.h"
#include "assets/Material.h"
#include <string.h>

RayTracer::RayTracer() {
	mShaderProgramsCount = 0;
	mVertexBuffersCount = 0;
	mIndexBuffersCount = 0;
	mTextureBuffersCount = 0;
}

void RayTracer::pushMatrix4(MatrixType type, const Matrix4& m) {
	mMatrixCache[(uint)type] = m;	
	switch (type)
	{
	case GraphicLibrary::MatrixType::World:
		mCurrentObject.World = m;
		break;
	// case GraphicLibrary::MatrixType::View:
	// 	mCurrentObject.View = m;
	// 	break;
	// case GraphicLibrary::MatrixType::Projection:
	// 	mCurrentObject.Projection = m;
	// 	break;
	default:
		break;
	}
}

void RayTracer::pushMaterial(const Material* material) {
	mCurrentObject.material = material;
}

void RayTracer::pushLights(const Light* lights, uint lightCount) {
	mLights.lights = lights;
	mLights.lightCount = lightCount;
}

void RayTracer::pushCamera(const Camera* camera) {
	mCamera = camera;
}

void RayTracer::pushAttributeValue(AttributeType type, const void* v, uint count) {
	// switch (type)
	// {
	// case GraphicLibrary::AttributeType::Position:
	// 	mCurrentObject.positions.values.vectors3 = (const Vector3*)v;
	// 	mCurrentObject.positions.count = count;
	// 	break;
	// case GraphicLibrary::AttributeType::Normal:
	// 	mCurrentObject.normals.values.vectors3 = (const Vector3*)v;
	// 	mCurrentObject.normals.count = count;
	// 	break;
	// case GraphicLibrary::AttributeType::UV0:
	// 	mCurrentObject.uvs.values.vectors2 = (const Vector2*)v;
	// 	mCurrentObject.uvs.count = count;
	// 	break;
	// case GraphicLibrary::AttributeType::UV1:
	// 	break;
	// case GraphicLibrary::AttributeType::UV2:
	// 	break;
	// default:
	// 	break;
	// }
}

void RayTracer::setVector3(uint uniformLocation, const Vector3& v) {

}

void RayTracer::setVector2(uint uniformLocation, const Vector2& v) {

}

void RayTracer::setMatrix4(uint uniformLocation, const Matrix4& m) {

}

unsigned int RayTracer::getUniformLocation(const char* uniformName) {
	return 0;
}

unsigned int RayTracer::getAttributeLocation(const char* attributeName) {
	return 0;
}

void RayTracer::enableAttribute(unsigned int attributeLocation) {
	VertexBuffer* buffer = &mVertexBuffers[attributeLocation];
	switch(buffer->format.type) {
		case GraphicLibrary::AttributeType::Position:
			mCurrentObject.positions = buffer;
			break;
		case GraphicLibrary::AttributeType::Normal:
			mCurrentObject.normals = buffer;
			break;
		case GraphicLibrary::AttributeType::UV0:
			mCurrentObject.uvs = buffer;
			break;
	}	
}

void RayTracer::disableAttribute(unsigned int attributeLocation) {

}

unsigned int RayTracer::createShaderProgram(Shader* shaderSource) {
	unsigned int shaderProgramLocation = mShaderProgramsCount;
	mShaderPrograms.emplace_back(shaderProgramLocation);
	mShaderProgramsCount++;
	return shaderProgramLocation;
}

unsigned int RayTracer::generateVertexBuffer() {
	unsigned int bufferLocation = mVertexBuffersCount;
	mVertexBuffers.emplace_back();
	mVertexBuffers[bufferLocation] = {};
	mVertexBuffersCount++;
	return bufferLocation;
}

unsigned int RayTracer::generateIndexBuffer() {
	unsigned int bufferLocation = mIndexBuffersCount;
	mIndexBuffers.emplace_back();
	mIndexBuffers[bufferLocation] = {};
	mIndexBuffersCount++;
	return bufferLocation;
}

uint RayTracer::generateTextureBuffer() {
	uint currentBuffer = mTextureBuffersCount;
	mTextureBuffersCount++;
	mTextureBuffers.emplace_back();
	return currentBuffer;
}

void RayTracer::bindTexture(uint textureLocation) {
	mCurrentTextureBuffer = &mTextureBuffers[textureLocation];
}

void RayTracer::bindTextureData(byte* data, TextureFormat format) {
	uint byte_size = format.width * format.height * format.channels;
	mCurrentTextureBuffer->data = new byte[byte_size];
	memcpy(mCurrentTextureBuffer->data, data, byte_size);
	mCurrentTextureBuffer->format = format;
}

void RayTracer::unbindTexture(uint textureLocation) {
	mCurrentTextureBuffer = nullptr;
}

void RayTracer::activeTexture(uint textureIndex) {
	mCurrentObject.texture = &mTextureBuffers[textureIndex];
}

void RayTracer::deactiveTexture(uint textureIndex) {

}


ShaderProgram* RayTracer::getShaderProgram(unsigned int shaderProgramLocation) {
	return &mShaderPrograms[shaderProgramLocation];
}

void RayTracer::bindShaderProgram(unsigned int shaderProgramLocation) {
	
}

void RayTracer::unbindShaderProgram(unsigned int shaderProgramLocation) {
	
}

void RayTracer::bindVertexBuffer(uint bufferLocation) {
	mCurrentVertexBuffer = &mVertexBuffers[bufferLocation];	
}

void RayTracer::bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector3> data) {
	mCurrentVertexBuffer->dataVector3 = data;
	mCurrentVertexBuffer->format = vertexFormat;
}

void RayTracer::bindVertexBufferData(VertexFormat vertexFormat, std::vector<Vector2> data) {
	mCurrentVertexBuffer->dataVector2 = data;
	mCurrentVertexBuffer->format = vertexFormat;
}

void RayTracer::unbindVertexBuffer(uint bufferLocation) {
	mCurrentVertexBuffer = nullptr;
}

void RayTracer::bindIndexBuffer(uint bufferLocation) {
	mCurrentIndexBuffer = &mIndexBuffers[bufferLocation];
	mCurrentObject.format = mCurrentIndexBuffer->format;
	mCurrentObject.indices = mCurrentIndexBuffer;
}

void RayTracer::bindIndexBufferData(ElementFormat elementFormat, std::vector<unsigned int> data) {
	mCurrentIndexBuffer->data = data;
	mCurrentIndexBuffer->format = elementFormat;
}

void RayTracer::unbindIndexBuffer(uint bufferLocation) {
	mCurrentIndexBuffer = nullptr;
}

void RayTracer::pushBackObject() {
	memset(&mCurrentObject, 0, sizeof(Object));
}

void RayTracer::clearObjectList() {
	mObjectsList.clear();
}

void RayTracer::drawElements() {
	mObjectsList.push_back(mCurrentObject);
}

void RayTracer::init() {
}

void RayTracer::setViewportRect(Rect rect) {
	mRect = rect;
	mBackBuffer.resize(rect.width * rect.height);
}

void* RayTracer::getBackBuffer() {
	return mBackBuffer.data();
}

void RayTracer::processObjectList() {
	
	Ray ray;
	float fov = mCamera->getFieldOfView();
	
	//const Matrix4& CameraToView = mCamera->getViewMatrix();
	const Vector3 cam_pos = mCamera->getTransform().getLocalPosition();//CameraToView[2];
	const Vector3 cam_up  = mCamera->getTransform().getUp();//CameraToView[1];
	const Vector3 cam_dir = mCamera->getTransform().getFront();//CameraToView[0];

	float scale = tan(Math::radians(fov * 0.5f));
    float imageAspectRatio = mRect.width / (float)mRect.height;

	Vector3 front = mCamera->getTransform().getFront();

	for (unsigned int j = 0; j < mRect.height; j++) {
		for (unsigned int i = 0; i < mRect.width; i++) {

			float x = (2.0f * (i + 0.5f) / (float)mRect.width - 1) * imageAspectRatio * scale; 
            float y = (1.0f - 2.0f * (j + 0.5f) / (float)mRect.height) * scale; 

			// ray.direction = CameraToView * Math::normalize(Vector4(x, y, -1.0f, 1.0f));
			ray = ComputeCameraRay(cam_pos, cam_dir, cam_up, i, j);
			mBackBuffer[i + mRect.width * j] = castRay(ray, 2);
		}
	}
}

Ray RayTracer::ComputeCameraRay(const Vector3& cam_pos, const Vector3& cam_dir, const Vector3& cam_up, int i, int j) {
	Vector3 cam_right = Math::cross(cam_up, cam_dir);
	const float width = mRect.width; // pixels across 
	const float height = mRect.height; // pixels high 
	float normalized_i = (i / width) - 0.5f;
	float normalized_j = (j / height) - 0.5f; 
	Vector3 image_point = normalized_i * cam_right + normalized_j * cam_up + cam_pos + cam_dir; 
	Vector3 ray_direction = image_point - cam_pos; 
	
	Ray ray;
	ray.origin = cam_pos;
	ray.direction = ray_direction;
	return ray;
}

PixelColor RayTracer::castRay(const Ray& ray, uint bounces) {

	RaycastHit hit;
	hit.object = nullptr;
	hit.closest = Infinity;
	if (rayCastHit(ray, hit)) {

		Color4 diffuseColor = calculatePointColor(ray, hit);
		PixelColor pixel;
		pixel.r = (byte)diffuseColor.r * 255; 
		pixel.g = (byte)diffuseColor.g * 255;
		pixel.b = (byte)diffuseColor.b * 255;
		pixel.a = (byte)diffuseColor.a * 255;
		return pixel;
	}

	return {128, 128, 255, 255};
}

Color4 RayTracer::calculatePointColor(const Ray& ray, const RaycastHit& hit) {

	Vector3 hitPoint = ray.origin + ray.direction * hit.closest;
	Vector3 N; // normal 
	Vector2 st; // st coordinates
	hit.object->getSurfaceProperties(hit.index, hit.uv, N, st);

	float bias = 0.00001f;
	Color4 lightAmt(0, 0, 0, 1); 
	Color4 specularColor(0, 0, 0, 1);
	Color4 sample(1, 1, 1, 1);

	if (hit.object->texture != nullptr) {
		sample = sampleTextureLinear(hit.object->texture, st);
	}

	Vector3 shadowPointOrig = (Math::dot(ray.direction, N) < 0) ? hitPoint + N * bias: hitPoint - N * bias;

	for (uint i = 0; i < mLights.lightCount; ++i) {
		Light* light = (Light*)&mLights.lights[i];
		Vector3 lightPosition = light->getTransform().getLocalPosition();
		Vector3 lightDir = lightPosition - hitPoint;
		// square of the distance between hitPoint and the light
		float lightDistance2 = Math::dot(lightDir, lightDir);
		lightDir = Math::normalize(lightDir);
		float LdotN = max(0.0f, Math::dot(lightDir, N));
		float tNearShadow = Infinity;

		// Verify if in the light or in the shadow
		Ray ray;
		ray.origin = shadowPointOrig;
		ray.direction = lightDir;
		RaycastHit newHit;

		bool inShadow = rayCastHit(ray, newHit) && tNearShadow * tNearShadow < lightDistance2;
		lightAmt += (1 - inShadow) * light->intensity * LdotN;
		Vector3 reflectionDirection = Math::reflect(-lightDir, N);
		float R_dot_Dir = fabs(Math::dot(reflectionDirection, ray.direction));
		float R_dot_Dir_Clamp = max(0.0f, R_dot_Dir);
		float specularTerm = powf(R_dot_Dir_Clamp, hit.object->material->shininess);
		// sample += specularTerm * hit.object->material->specular * light->intensity;
		specularColor += sample;
	}

	return specularColor;
}

bool RayTracer::rayCastHit(const Ray& ray,  RaycastHit& hit) {

	float nearest = Infinity;
	for (Object& object : mObjectsList)
		if (object.intersect(ray, hit))
			if (hit.closest < nearest) {
				hit.object = &object;
				nearest = hit.closest;
			}

	return hit.object != nullptr;
}

float RayTracer::Diffuse(const Vector3& N, const Vector3& L) {
	return max(0.0f, Math::dot(N, L));
}

float RayTracer::Specular(const Vector3& N, const Vector3& L, const Vector3& E, const float shininess) {
	Vector3 H = Math::normalize(E + L);
	return Math::pow(max(0.0f, Math::dot(N, H)), shininess);
}

Color RayTracer::Phong(const Light* light, float diffuse, float specular, Color diffuseColor, Color specularColor) {
	// float3 N = normalize(mul(IN.outnormal, worldInverseTranspose)); //normal vector
    // float3 E = normalize(worldEyePos - worldVertPos); //eye vector
    // float3 L = normalize( -lightDir.xyz); //light vector
    if(diffuse <= 0) specular = 0;

	//output diffuse
    Color ambColor = diffuseColor * Color(0.5, 0.5, 0.5);
    Color diffColor = diffuseColor * diffuse * light->color ;
    Color diffAmbColor = diffColor + ambColor;

	//output specular
    Color specColor = specularColor * light->color * specular;
    return specColor;
}

Color4 RayTracer::sampleTextureLinear(const TextureBuffer* textureBuffer, const Vector2& st) {
	//TODO: implement another type of interpolation formats
	uint imin = floor(st.x);
	uint jmin = floor(st.y);

	uint imax = ceil(st.x);
	uint jmax = ceil(st.y);

	Color4 colormin(0, 0, 0, 0);
	Color4 colormax(0, 0, 0, 0);
	textureBuffer->sample(colormin, imin, jmin);
	textureBuffer->sample(colormax, imax, jmax);

	return Math::mix(colormin, colormax, 0.5f);
}