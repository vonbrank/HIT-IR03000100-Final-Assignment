//
// Created by VonBrank on 2022/4/6.
//

#include "Camera.h"
#include "../Utils/Utils.h"
#include <iostream>

Camera::Camera(float fov, float width, float height, float near, float far, Vector3 cameraPos)
        : cameraPos(cameraPos.x, cameraPos.y, cameraPos.z), cameraFront(0, 0, -1), cameraUp(0, 1, 0),
          fov(fov), width(width), height(height), near(near), far(far), verticalRotationAngle(0)
{
    view = glm::lookAt(this->cameraPos, this->cameraPos + cameraFront, cameraUp);
    projection = glm::perspective(glm::radians(fov), width / height, near, far);

    verticalRotationSpeedAttenuationCoefficient = 90.0f;
    verticalRotationAcceleration = 180.0f;
    verticalRotationMaxSpeed = 360.0f;
}

glm::mat4 Camera::getView() const
{
    return view;
}

glm::mat4 Camera::getProjection() const
{
    return projection;
}

glm::vec3 Camera::getViewPos() const
{
    return cameraPos;
}

void Camera::setAspect(float width, float height)
{
    this->width = width;
    this->height = height;
    projection = glm::perspective(glm::radians(fov), width / height, near, far);
}

void Camera::processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_LEFT) && verticalRotationSpeed < verticalRotationMaxSpeed)
    {
        verticalRotationSpeed += verticalRotationAcceleration * (*deltaTimePointer);
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) && verticalRotationSpeed > -verticalRotationMaxSpeed)
    {
        verticalRotationSpeed -= verticalRotationAcceleration * (*deltaTimePointer);
    }
}

void Camera::update()
{
    Utils::linearAttenuation(verticalRotationSpeed, verticalRotationSpeedAttenuationCoefficient, *deltaTimePointer);
    verticalRotationAngle += verticalRotationSpeed * (*deltaTimePointer);
//    std::cout << verticalRotationSpeed << std::endl;
    cameraPos.x = 3 * cos(glm::radians(verticalRotationAngle + 90));
    cameraPos.z = 3 * sin(glm::radians(verticalRotationAngle + 90));
    cameraFront = -cameraPos;
    view = glm::lookAt(this->cameraPos, this->cameraPos + cameraFront, cameraUp);
}
