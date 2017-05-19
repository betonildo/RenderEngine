#include "Assets/Texture.h"

Texture::Texture() {
}

Texture::Texture(const Texture& other) {
    m_textureID = other.m_textureID;
    m_textureIndex = other.m_textureIndex;
}

Texture::~Texture() {
    glDeleteTextures(1, &m_textureID);
}

void Texture::load(const char* relativePath) {
    
    /* load an image as a heightmap, forcing greyscale (so channels should be 1) */
    int width, height, channels;
    unsigned char *ht_map = SOIL_load_image
	(
		relativePath, &width, &height, &channels, SOIL_LOAD_L
	);

    for (int i = 0; i < width * height; i++) {
        ht_map[i] = 255;
    }

    if (ht_map == NULL) {
        printf("Image: \"%s\" not loaded\n", relativePath);
        return;
    }

    int Mode = GL_RGB;    
    if(channels == 4) Mode = GL_RGBA;
    
    // Nice trilinear filtering.
    // TODO: Parameterize texture parameters
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, width, height, 0, Mode, GL_UNSIGNED_BYTE, ht_map);

    /* done with the heightmap, free up the RAM */
    SOIL_free_image_data( ht_map );
}

void Texture::setTextureIndex(unsigned int textureIndex) {
    m_textureIndex = textureIndex;
}   


unsigned int Texture::use() const{

    // TODO: Create bind active buffer index
    unsigned int textureRealID = GL_TEXTURE0 + m_textureIndex;
    glActiveTexture(textureRealID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    return m_textureID;
}