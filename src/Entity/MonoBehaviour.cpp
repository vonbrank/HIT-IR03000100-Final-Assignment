//
// Created by VonBrank on 2022/4/5.
//

#include "MonoBehaviour.h"

void MonoBehaviour::awake()
{}

void MonoBehaviour::start()
{}

void MonoBehaviour::update()
{}

void MonoBehaviour::processInput(GLFWwindow *window)
{}

void MonoBehaviour::setInputDataModel(InputDataModel *inputDataModel)
{
    this->inputDataModel = inputDataModel;
}