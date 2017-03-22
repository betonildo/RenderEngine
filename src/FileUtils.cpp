#include "FileUtils.h"

std::string FileUtils::readAllText(std::string filePath) {
    return FileUtils::readAllText(filePath.c_str());
}

std::string FileUtils::readAllText(const char* filePath) {

    std::string content = "";
    std::ifstream ifs (filePath, std::ifstream::binary);

    if (ifs) {
        content = ifs.get();

        while (ifs.good()) {
            content += ifs.get();
        }

        ifs.close();
    }

    return content;
}