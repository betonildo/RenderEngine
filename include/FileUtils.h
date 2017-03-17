#include "renderer_local_includes.h"

#ifndef FILEUTILS_H
#define FILEUTILS_H

class FileUtils {

public:
    static char* readAllText(std::string filePaht);
    static char* readAllText(const char* filePath);

};

#endif /*FILEUTILS_H*/