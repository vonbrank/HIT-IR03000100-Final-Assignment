//
// Created by VonBrank on 2022/4/5.
//

#include "OpenGLContainer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "Utils/Utils.h"

OpenGLContainer *OpenGLContainer::thisPtr;
InputDataModel OpenGLContainer::inputDataModel;

OpenGLContainer::OpenGLContainer(unsigned int screenWidth, unsigned int screenHeight, const std::string &windowTitle)
        : camera(45.0f, screenWidth, screenHeight, 0.1, 100, Vector3(0, 0, 3)),
//          light(Color(1.0f, 0.5f, 0.2f, 1.0f),
          light(Color(1.0f, 1.0f, 1.0f, 1.0f), Vector3(-50, 0, 50)),
          screenWidth(screenWidth), screenHeight(screenHeight)
{
    thisPtr = this;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->
            window = glfwCreateWindow(
            screenWidth,
            screenHeight,
            windowTitle.c_str(), nullptr, nullptr);

    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" <<
                  std::endl;

        glfwTerminate();

        exit(-1);
    }
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback
    );
    glfwSetMouseButtonCallback(window, mouse_callback
    );

    Utils::checkGladLoad();

    addObject(&camera);
//    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        glfwTerminate();
//        exit(-1);
//    }

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
    object->setInputDataModel(&(this->inputDataModel));
}

void OpenGLContainer::addSpriteRenderer(SpriteRenderer *spriteRenderer)
{
    this->objectList.push_back(spriteRenderer);
    spriteRenderer->setCameraPointer(&(this->camera));;
    spriteRenderer->deltaTimePointer = &(this->deltaTime);
    spriteRenderer->setLightPointer(&(this->light));
    spriteRenderer->setInputDataModel(&(this->inputDataModel));
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
    double x, y;
    glfwGetCursorPos(window, &x, &y);
//    std::cout << x << ", " << y << std::endl;
    inputDataModel.mouseMoveSpeedX = (x - inputDataModel.mouseCursorPosX) / deltaTime;
    inputDataModel.mouseMoveSpeedY = (y - inputDataModel.mouseCursorPosY) / deltaTime;
    inputDataModel.mouseMoveSpeedPercentageX = inputDataModel.mouseMoveSpeedX / screenWidth;
    inputDataModel.mouseMoveSpeedPercentageY = inputDataModel.mouseMoveSpeedY / screenHeight;

    inputDataModel.mouseCursorPosX = x;
    inputDataModel.mouseCursorPosY = y;

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


void OpenGLContainer::frame_buffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
    thisPtr->camera.setAspect(width, height);
}

void OpenGLContainer::mouse_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (GLFW_PRESS == action)
            inputDataModel.leftButtonDown = true;
        else if (GLFW_RELEASE == action)
            inputDataModel.leftButtonDown = false;
    }
//    std::cout << inputDataModel.leftButtonDown << std::endl;
}
