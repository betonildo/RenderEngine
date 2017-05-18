#include "Assets/Texture.h"

Texture::Texture() {
    glGenTextures(1, &m_textureID);
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
    
    if (ht_map == NULL) {
        printf("Image: \"%s\" not loaded\n", relativePath);
        return;
    }

    glBindTexture(GL_TEXTURE_2D, m_textureID);
    
    int Mode = GL_RGB;
    
    if(channels == 4)
        Mode = GL_RGBA;
    
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, width, height, 0, Mode, GL_UNSIGNED_BYTE, ht_map);
    glGetError();
    // Nice trilinear filtering.
    // TODO: Parameterize texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // glGenerateMipmap(GL_TEXTURE_2D);

    printf("Image Width: %d\n", width);
    printf("Image height: %d\n", height);

	
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

    return m_textureIndex;
}