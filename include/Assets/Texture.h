#ifndef TEXTURE_H
#define TEXTURE_H

#include "Asset.h"

class Asset;

class Texture: public Asset {

public:
    virtual void load(const char* relativePath);

};

#endif /*TEXTURE_H*/
