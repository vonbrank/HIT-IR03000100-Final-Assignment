//
// Created by VonBrank on 2022/4/1.
//

#ifndef OPENGL_LEARNING_CMAKE_LOADTEXTURE_H
#define OPENGL_LEARNING_CMAKE_LOADTEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class TextureLoader {
public:
    static void load(const char* texturePath, int colorType = GL_RGB);
};


#endif //OPENGL_LEARNING_CMAKE_LOADTEXTURE_H
