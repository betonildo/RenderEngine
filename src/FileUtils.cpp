#include "FileUtils.h"

std::string FileUtils::readAllText(std::string filePath) {
    return FileUtils::readAllText(filePath.c_str());
}

std::string FileUtils::readAllText(const char* filePath) {

    FILE* fp = fopen(filePath, "r");

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char* buffer = new unsigned char[size + 1];
    memset(buffer, 0, sizeof(unsigned char) * size);
    fread(buffer, sizeof(unsigned char), size, fp);
    buffer[size] = '\0';
    std::string content((const char*)buffer);

    return content;
}