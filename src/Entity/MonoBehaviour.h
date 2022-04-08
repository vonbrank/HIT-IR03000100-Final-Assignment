//
// Created by VonBrank on 2022/4/5.
//

#ifndef SPHERE_SHADING_MONOBEHAVIOUR_H
#define SPHERE_SHADING_MONOBEHAVIOUR_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../DataModel/InputDataModel.hpp"
#include "../DataModel/InputDataModel.hpp"

class MonoBehaviour
{
public:
    float *deltaTimePointer;
    InputDataModel *inputDataModel;

    virtual void start();

    virtual void awake();

    virtual void update();

    virtual void processInput(GLFWwindow *window);

    virtual void setInputDataModel(InputDataModel *inputDataModel);
};


#endif //SPHERE_SHADING_MONOBEHAVIOUR_H
