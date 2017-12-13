#include <GL/glew.h>
#include <string>
#include "graphics/library/OpenGL/OpenGLShaderCompiler.h"
#include "graphics/library/OpenGL/OpenGLErrorHandling.h"

OpenGLShaderCompiler::OpenGLShaderCompiler() {

}

void OpenGLShaderCompiler::readVertexAndFragmentShaderFromSource(const char* shaderSource, unsigned int length) {
	std::string source;
	source.assign(shaderSource, length);

	unsigned int beginVertShaderPosition = source.find("#BEGIN VERTEXSHADER");
	unsigned int endVertShaderPosition = source.find("#END VERTEXSHADER");
	unsigned int vertSourcePositionsCount = endVertShaderPosition - beginVertShaderPosition;
	mVertShaderSource = source.substr(beginVertShaderPosition, vertSourcePositionsCount);


	unsigned int beginFragShaderPosition = source.find("#BEGIN FRAGMENTSHADER");
	unsigned int endFragShaderPosition = source.find("#END FRAGMENTSHADER");
	unsigned int fragSourcePositionsCount = endFragShaderPosition - beginFragShaderPosition;
	mFragShaderSource = source.substr(beginFragShaderPosition, fragSourcePositionsCount);

	std::cout << "Vertex Shader Source: " << mVertShaderSource << std::endl;
	std::cout << "Fragment Shader Source: " << mFragShaderSource << std::endl;
}

unsigned int OpenGLShaderCompiler::compileAndGetVertexShaderHandle() {
	mVertShaderPointer = compileShader(mVertShaderSource, GL_VERTEX_SHADER);
	return mVertShaderPointer;
}

unsigned int OpenGLShaderCompiler::compileAndGetFragmentShaderHandle() {
	mFragShaderPointer = compileShader(mFragShaderSource, GL_FRAGMENT_SHADER);
	return mFragShaderPointer;
}

unsigned int OpenGLShaderCompiler::compileShader(std::string source, unsigned int type) {
	GLCall(unsigned int shader = glCreateShader(type));
	const char* shaderSource = source.c_str();
	GLCall(glShaderSource(shader, 1, &shaderSource, 0));

	
	GLCall(glCompileShader(shader));
	
	GLint isCompiled = 0;
	GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled));
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength));

		//The maxLength includes the NULL character
		auto infoLog = new GLchar[maxLength + 1];
		GLCall(glGetShaderInfoLog(shader, maxLength, &maxLength, infoLog));

		printf("%s\n", infoLog);

		GLCall(glDeleteShader(shader));
		return -1;
	}

	return shader;
}

unsigned int OpenGLShaderCompiler::attachShadersAndGetProgramHandle() {
	return 0;
}