//
// Created by VonBrank on 2022/4/7.
//

#ifndef SPHERE_SHADING_LIGHT_H
#define SPHERE_SHADING_LIGHT_H

#include "MonoBehaviour.h"
#include "../Utils/Vector.hpp"
#include "../Utils/Color.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Light : MonoBehaviour
{
private:
    glm::vec4 lightColor;
    glm::vec3 lightPos;
public:
    Light(Color lightColor, Vector3 lightPos);
    glm::vec4 getLightColor();
    glm::vec3 getLightPos();
};


#endif //SPHERE_SHADING_LIGHT_H
