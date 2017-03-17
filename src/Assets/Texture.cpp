#include "Texture.h"

Texture::Texture() {
    glGenTextures(1, &m_textureID);
}

Texture::~Texture() {
    glDeleteTextures(1, &m_textureID);
}

void Texture::load(const char* relativePath) {
    
    SDL_Surface* Surface = IMG_Load(relativePath);
    
    
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    
    int Mode = GL_RGB;
    
    if(Surface->format->BytesPerPixel == 4)
        Mode = GL_RGBA;
    
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, Surface->w, Surface->h, 0, Mode, GL_UNSIGNED_BYTE, Surface->pixels);
    
    // Nice trilinear filtering.
    // TODO: Parameterize texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);

    SDL_FreeSurface(Surface);
}

void Texture::setTextureIndex(unsigned int textureIndex) {
    m_textureIndex = textureIndex;
}   


unsigned int Texture::use() {
    // TODO: Create bind active buffer index
    unsigned int textureRealID = GL_TEXTURE0 + m_textureIndex;
    glActiveTexture(textureRealID); 
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    return textureRealID;
}