//
// Created by VonBrank on 2022/4/5.
//

#ifndef SPHERE_SHADING_OPENGLCONTAINER_H
#define SPHERE_SHADING_OPENGLCONTAINER_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Utils/Color.hpp"
#include <vector>
#include "Entity/MonoBehaviour.h"
#include "Entity/SpriteRenderer.h"
#include "Entity/Camera.h"
#include "Entity/Light.h"
#include "DataModel/InputDataModel.hpp"


class OpenGLContainer
{
private:
    GLFWwindow *window;
    Color clearColor;
    std::vector<MonoBehaviour *> objectList;
    Camera camera;
    float currentTime;
    float lastTime;
    float deltaTime;
    Light light;
    static InputDataModel inputDataModel;
    unsigned int screenWidth, screenHeight;

    static void frame_buffer_size_callback(GLFWwindow *window, int width, int height);

    static void mouse_callback(GLFWwindow *window, int button, int action, int mods);

    static OpenGLContainer *thisPtr;

public:
    float* anglePointer;
    OpenGLContainer(unsigned int screenWidth, unsigned int screenHeight, const std::string &windowTitle);

    void addObject(MonoBehaviour *object);

    void addSpriteRenderer(SpriteRenderer *spriteRenderer);

    void update();

    void processInput(GLFWwindow *window);

    void run();

    ~OpenGLContainer();


};


#endif //HIT_IR03000100_FINAL_ASSIGNMENT_OPENGLCONTAINER_H
