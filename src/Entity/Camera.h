//
// Created by VonBrank on 2022/4/6.
//

#ifndef SPHERE_SHADING_CAMERA_H
#define SPHERE_SHADING_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "MonoBehaviour.h"
#include "../Utils/Vector.hpp"

class Camera : MonoBehaviour
{
private:
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::mat4 view;
    glm::mat4 projection;
public:
    Camera(float fov, float width, float height, float near, float far, Vector3 cameraPos);
    glm::mat4 getView() const;
    glm::mat4 getProjection() const;
    glm::vec3  getViewPos() const;
};


#endif //SPHERE_SHADING_CAMERA_H
