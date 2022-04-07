//
// Created by VonBrank on 2022/4/1.
//

#include "TextureLoader.h"

#define STB_IMAGE_IMPLEMENTATION1
#include <stb_image.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void TextureLoader::load(const char *texturePath, int colorType) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, colorType, width, height, 0, colorType, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture1" << std::endl;
    }
}