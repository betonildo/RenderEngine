#include "renderer_local_includes.h"

#ifndef ASSET_H
#define ASSET_H

class Asset {

public:
    virtual void load(const char* relativePath) = 0;
    inline Asset() {}
    inline Asset(const Asset& other) {
        memcpy((void*)this, (const void*)&other, sizeof(Asset));
    }
};

#endif /*ASSET_H*/