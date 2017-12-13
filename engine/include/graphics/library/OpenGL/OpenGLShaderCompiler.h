#ifndef OPENGLSHADERCOMPILER_H
#define OPENGLSHADERCOMPILER_H

#include <iostream>

class OpenGLShaderCompiler {

public:
	OpenGLShaderCompiler();
	void readVertexAndFragmentShaderFromSource(const char* shaderSource, unsigned int length);
	unsigned int compileAndGetVertexShaderHandle();
	unsigned int compileAndGetFragmentShaderHandle();
	unsigned int compileShader(std::string source, unsigned int type);
	unsigned int attachShadersAndGetProgramHandle();

private:
	std::string mVertShaderSource;
	std::string mFragShaderSource;

	unsigned int mVertShaderPointer;
	unsigned int mFragShaderPointer;
};

#endif /*SHADERCOMPILER_H*/