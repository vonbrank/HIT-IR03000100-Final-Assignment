//
// Created by VonBrank on 2022/3/31.
//

#ifndef OPENGL_LEARNING_CMAKE_UTILS_H
#define OPENGL_LEARNING_CMAKE_UTILS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Utils {
public:
    static void checkShaderCompileSuccess(unsigned int shader);
    static void checkShaderProgramLinkSuccess(unsigned int shaderProgram);
    static void frame_buffer_size_callback(GLFWwindow *window, int width, int height);
    static void processInput(GLFWwindow *window);
    static void checkWindow(GLFWwindow *window);
    static void checkGladLoad();
};


#endif //OPENGL_LEARNING_CMAKE_UTILS_H
