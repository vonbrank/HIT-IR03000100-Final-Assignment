//
// Created by VonBrank on 2022/4/5.
//

#ifndef SPHERE_SHADING_OPENGLCONTAINER_H
#define SPHERE_SHADING_OPENGLCONTAINER_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Color.hpp"

class OpenGLContainer {
private:
    GLFWwindow *window;
    Color clearColor;

public:
    OpenGLContainer(unsigned int screenWidth, unsigned int screenHeight, const std::string &windowTitle);
    void run();
    ~OpenGLContainer();
};


#endif //HIT_IR03000100_FINAL_ASSIGNMENT_OPENGLCONTAINER_H
