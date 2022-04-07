//
// Created by VonBrank on 2022/4/5.
//

#include "OpenGLContainer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

OpenGLContainer::OpenGLContainer(unsigned int screenWidth, unsigned int screenHeight, const std::string &windowTitle)
        : camera(45.0f, 800, 600, 0.1, 100, Vector3(0, 0, 3)),
//          light(Color(1.0f, 0.5f, 0.2f, 1.0f),
          light(Color(1.0f, 1.0f, 1.0f, 1.0f),
                Vector3(5, 0, 5))
{
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

    glEnable(GL_DEPTH_TEST);
    currentTime = 0;
    lastTime = 0;
    deltaTime = 0;

}

void OpenGLContainer::addObject(MonoBehaviour *object)
{
    this->objectList.push_back(object);
    object->deltaTimePointer = &(this->deltaTime);

}

void OpenGLContainer::addSpriteRenderer(SpriteRenderer *spriteRenderer)
{
    this->objectList.push_back(spriteRenderer);
    spriteRenderer->setCameraPointer(&(this->camera));;
    spriteRenderer->deltaTimePointer = &(this->deltaTime);
    spriteRenderer->setLightPointer(&(this->light));
}

void OpenGLContainer::update()
{
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
//    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->processInput(window);

    for (MonoBehaviour *monoBehaviour: objectList)
    {
        monoBehaviour->processInput(window);
    }

    for (MonoBehaviour *monoBehaviour: objectList)
    {
        monoBehaviour->update();
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void OpenGLContainer::processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE)) glfwSetWindowShouldClose(window, true);
}

void OpenGLContainer::run()
{
    while (!glfwWindowShouldClose(window))
    {
        this->update();
    }
}

OpenGLContainer::~OpenGLContainer()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

