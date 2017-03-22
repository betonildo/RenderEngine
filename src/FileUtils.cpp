#include "FileUtils.h"

std::string FileUtils::readAllText(std::string filePath) {
    return FileUtils::readAllText(filePath.c_str());
}

std::string FileUtils::readAllText(const char* filePath) {

    FILE* fp = fopen(filePath, "rb");
    fseek(fp, 0, SEEK_END);
    unsigned long fileSize = ftell(fp);
    rewind(fp);

    char* buffer = (char*)malloc(sizeof(char) * fileSize);
    fread(buffer, sizeof(char), fileSize, fp);
    fclose(fp);
    return std::string(buffer);
}