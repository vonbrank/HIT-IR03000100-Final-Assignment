//
// Created by VonBrank on 2022/4/6.
//

#include "Camera.h"

Camera::Camera(float fov, float width, float height, float near, float far, Vector3 cameraPos)
        : cameraPos(cameraPos.x, cameraPos.y, cameraPos.z), cameraFront(0, 0, -1), cameraUp(0, 1, 0)
{
    view = glm::lookAt(this->cameraPos, this->cameraPos + cameraFront, cameraUp);
    projection = glm::perspective(glm::radians(fov), width / height, near, far);
}

glm::mat4 Camera::getView() const
{
    return view;
}

glm::mat4 Camera::getProjection() const
{
    return projection;
}