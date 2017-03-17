#include "Asset.h"

#ifndef TEXTURE_H
#define TEXTURE_H


class Asset;

class Texture: public Asset {

public:
    Texture();
    ~Texture();
    virtual void load(const char* relativePath);
    void use();
    
private:
    unsigned int m_textureID;

};

#endif /*TEXTURE_H*/
