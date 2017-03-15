#ifndef SHADER_H
#define SHADER_H

#include "Asset.h"

class Shader : public Asset {

public:
    virtual void load(const char* relativePath);
    void 
    void compile();
    void use();


private:
    unsigned int m_program;
};

#endif /*SHADER_H*/