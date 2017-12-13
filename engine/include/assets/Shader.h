#ifndef SHADER_H
#define SHADER_H

#include "OSExport.h"
#include "assets/Asset.h"
#include <string>

class ENGINE_API Shader : public Asset {

public:
	Shader(std::string source) : source(source) {}
    std::string source;
};

#endif /*SHADER_H*/