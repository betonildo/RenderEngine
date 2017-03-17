#include "FileUtils.h"

char* FileUtils::readAllText(std::string filePath) {
    return FileUtils::readAllText(filePath.c_str());
}

char* FileUtils::readAllText(const char* filePath) {

    SDL_RWops *rw = SDL_RWFromFile(filePath, "rb");
    if (rw == NULL) return NULL;

    Sint64 res_size = SDL_RWsize(rw);
    char* res = (char*)malloc(res_size + 1);

    Sint64 nb_read_total = 0, nb_read = 1;
    char* buf = res;
    while (nb_read_total < res_size && nb_read != 0) {
            nb_read = SDL_RWread(rw, buf, 1, (res_size - nb_read_total));
            nb_read_total += nb_read;
            buf += nb_read;
    }
    SDL_RWclose(rw);
    if (nb_read_total != res_size) {
            free(res);
            return NULL;
    }

    res[nb_read_total] = '\0';
    return res;
}