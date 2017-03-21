#include "renderer_local_includes.h"

#ifndef FILEUTILS_H
#define FILEUTILS_H

class FileUtils {

public:
    static char* readAllText(std::string filePath);
    static char* readAllText(const char* filePath);
    static std::vector<std::string> readAllLinesAsText(std::string filePath);
    static std::vector<std::string> readAllLinesAsText(const char* filePath);
};

#endif /*FILEUTILS_H*/