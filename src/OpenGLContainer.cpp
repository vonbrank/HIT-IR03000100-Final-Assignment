//
// Created by VonBrank on 2022/4/5.
//

#include "OpenGLContainer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

OpenGLContainer::OpenGLContainer(unsigned int screenWidth, unsigned int screenHeight, const std::string &windowTitle) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(
            screenWidth,
            screenHeight,
            windowTitle.c_str(), nullptr, nullptr);

    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glViewport(0, 0, screenWidth, screenHeight);

    clearColor = Color(0.03f, 0.12f, 0.20f, 1.0f);
}

void OpenGLContainer::run() {
    while (!glfwWindowShouldClose(window))
    {

        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

OpenGLContainer::~OpenGLContainer() {
    glfwDestroyWindow(this->window);
    glfwTerminate();
}