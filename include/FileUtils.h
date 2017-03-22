#include "renderer_local_includes.h"

#ifndef FILEUTILS_H
#define FILEUTILS_H

class FileUtils {

public:
    static std::string readAllText(std::string filePath);
    static std::string readAllText(const char* filePath);
};

#endif /*FILEUTILS_H*/