#include "Assets/Shader.h"

Shader::Shader() {
    m_program = glCreateProgram();
    m_fragment = glCreateShader(Shader::ShaderType::Fragment);
    m_vertex = glCreateShader(Shader::ShaderType::Vertex);
}

Shader::~Shader() {

}

void Shader::load(const char* relativePath) {
    #if defined(OPENGL)

        std::string vertFilePath = std::string(relativePath).append(".vert");
        std::string fragFilePath = std::string(relativePath).append(".frag");

        std::string vert = FileUtils::readAllText(vertFilePath);
        std::string frag = FileUtils::readAllText(fragFilePath);

        m_compileProgram(m_vertex, (char*)vert.c_str());
        m_compileProgram(m_fragment, (char*)frag.c_str());
        m_link();
    #endif
}

void Shader::use() {
    glUseProgram(m_program);
}

void Shader::setVector2(unsigned int uniform, const glm::vec2& v) {
    glUniform2fv(uniform, 1, (const float*)&v);
}

void Shader::setVector3(unsigned int uniform, const glm::vec3& v) {
    glUniform3fv(uniform, 1, (const float*)&v);
}

void Shader::setVector4(unsigned int uniform, const glm::vec4& v) {
    glUniform4fv(uniform, 1, (const float*)&v);
}

void Shader::setMatrix4(unsigned int uniform, const glm::mat4& m) {
    glUniformMatrix4fv(uniform, 1, false, (const float*) &m);
}

void Shader::setTexture(unsigned int uniform, const Texture& t) {
    glUniform1i(uniform, t.use());
}

unsigned int Shader::getUniformLocation(const char* uniform) {
    return glGetUniformLocation(m_program, uniform);
}

unsigned int Shader::getAttributeLocation(const char* attribute) {
    return glGetAttribLocation(m_program, attribute);
}

void Shader::m_compileProgram(unsigned int programID, char* source) {

    //Send the vertex shader source code to GL
    glShaderSource(programID, 1, &source, 0);

    //Compile the vertex shader
    glCompileShader(programID);

    int isCompiled = 0;
    glGetShaderiv(programID, GL_COMPILE_STATUS, &isCompiled);
    
    if(isCompiled == false) {

        GLsizei maxLength = 0;
        glGetShaderiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

        //The maxLength includes the NULL character
        char* infoLog = new char[maxLength + 1];
        glGetShaderInfoLog(programID, maxLength, &maxLength, &infoLog[0]);
        
        //We don't need the shader anymore.
        glDeleteShader(programID);

        //Use the infoLog as you see fit.
        printf("Compile Error: %s\n", infoLog);
        //In this simple program, we'll just leave
        return;
    }
}

void Shader::m_link() {

    //Attach our shaders to our program
    glAttachShader(m_program, m_vertex);
    glAttachShader(m_program, m_fragment);

    //Link our program
    glLinkProgram(m_program);

    //Note the different functions here: glGetProgram* instead of glGetShader*.
    int isLinked = 0;
    glGetProgramiv(m_program, GL_LINK_STATUS, &isLinked);

    if(isLinked == false) {

        GLsizei maxLength = 0;
        glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &maxLength);

        //The maxLength includes the NULL character
        char* infoLog = new char[maxLength + 1];
        glGetProgramInfoLog(m_program, maxLength, &maxLength, &infoLog[0]);
        
        //We don't need the program anymore.
        glDeleteProgram(m_program);
        //Don't leak shaders either.
        glDeleteShader(m_vertex);
        glDeleteShader(m_fragment);

        //Use the infoLog as you see fit.        
        //In this simple program, we'll just leave
        return;
    }

    //Always detach shaders after a successful link.
    glDetachShader(m_program, m_vertex);
    glDetachShader(m_program, m_fragment);
}