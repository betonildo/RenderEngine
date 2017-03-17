#include "Asset.h"

#ifndef TEXTURE_H
#define TEXTURE_H


class Asset;

class Texture: public Asset {

public:
    Texture();
    ~Texture();
    virtual void load(const char* relativePath);
    void setTextureIndex(unsigned int textureIndex);
    unsigned int use();
    
private:
    unsigned int m_textureID;
    unsigned int m_textureIndex;
};

#endif /*TEXTURE_H*/
