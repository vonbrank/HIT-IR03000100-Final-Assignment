//
// Created by VonBrank on 2022/4/6.
//

#include "Camera.h"
#include "../Utils/Utils.h"
#include <iostream>

Camera::Camera(float fov, float width, float height, float near, float far, Vector3 cameraPos)
        : cameraPos(cameraPos.x, cameraPos.y, cameraPos.z), cameraFront(0, 0, -1), cameraUp(0, 1, 0),
          fov(fov), width(width), height(height), near(near), far(far), horizontalRotationAngle(0)
{
    view = glm::lookAt(this->cameraPos, this->cameraPos + cameraFront, cameraUp);
    projection = glm::perspective(glm::radians(fov), width / height, near, far);

    horizontalRotationSpeedAttenuationCoefficient = 90.0f;
    horizontalRotationAcceleration = 180.0f;
    horizontalRotationMaxSpeed = 360.0f;

//    verticalRotationAngle = 30.0f;
    verticalRotationSpeedAttenuationCoefficient = 90.0f;
    verticalRotationAcceleration = 180.0f;
    verticalRotationMaxSpeed = 360.0f;
    verticalRotationSafeDistance = 20.0f;
    verticalRotationSafeBound = 80.0f;
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
    if (glfwGetKey(window, GLFW_KEY_LEFT) && horizontalRotationSpeed < horizontalRotationMaxSpeed)
        horizontalRotationSpeed += horizontalRotationAcceleration * (*deltaTimePointer);
    if (glfwGetKey(window, GLFW_KEY_RIGHT) && horizontalRotationSpeed > -horizontalRotationMaxSpeed)
        horizontalRotationSpeed -= horizontalRotationAcceleration * (*deltaTimePointer);
    if (glfwGetKey(window, GLFW_KEY_UP) && verticalRotationSpeed < verticalRotationMaxSpeed)
        verticalRotationSpeed += verticalRotationAcceleration * (*deltaTimePointer);
    if (glfwGetKey(window, GLFW_KEY_DOWN) && verticalRotationSpeed > -verticalRotationMaxSpeed)
        verticalRotationSpeed -= verticalRotationAcceleration * (*deltaTimePointer);
}

void Camera::update()
{
    Utils::linearAttenuation(horizontalRotationSpeed, horizontalRotationSpeedAttenuationCoefficient, *deltaTimePointer);
    Utils::linearAttenuation(verticalRotationSpeed, verticalRotationSpeedAttenuationCoefficient, *deltaTimePointer);
    if ((verticalRotationSpeed > 0 && verticalRotationSafeBound - verticalRotationAngle < verticalRotationSafeDistance))
    {
        float expectationAcceleration = -verticalRotationSpeed * verticalRotationSpeed /
                                        (2 * (verticalRotationSafeBound - verticalRotationAngle));

        if (verticalRotationAcceleration > expectationAcceleration)
        {
            verticalRotationSpeed += expectationAcceleration * (*deltaTimePointer);
            verticalRotationSpeed -= verticalRotationAcceleration * (*deltaTimePointer);
        }
    } else if (verticalRotationSpeed < 0 &&
               verticalRotationAngle - (-verticalRotationSafeBound) < verticalRotationSafeDistance)
    {
        float expectationAcceleration = -verticalRotationSpeed * verticalRotationSpeed /
                                        (2 * (verticalRotationAngle - (-verticalRotationSafeBound)));
        if (verticalRotationAcceleration > expectationAcceleration)
        {
            verticalRotationSpeed -= expectationAcceleration * (*deltaTimePointer);
            verticalRotationSpeed += verticalRotationAcceleration * (*deltaTimePointer);
        }
    }
    horizontalRotationAngle += horizontalRotationSpeed * (*deltaTimePointer);
    verticalRotationAngle += verticalRotationSpeed * (*deltaTimePointer);
//    std::cout << verticalRotationSpeed << std::endl;
    cameraPos.x = 3 * cos(glm::radians(verticalRotationAngle)) * cos(glm::radians(horizontalRotationAngle + 90));
    cameraPos.z = 3 * cos(glm::radians(verticalRotationAngle)) * sin(glm::radians(horizontalRotationAngle + 90));
    cameraPos.y = 3 * sin(glm::radians(verticalRotationAngle));
    cameraFront = -cameraPos;
    view = glm::lookAt(this->cameraPos, this->cameraPos + cameraFront, cameraUp);
}
