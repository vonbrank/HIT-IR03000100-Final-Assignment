//
// Created by VonBrank on 2022/4/7.
//

#include "Light.h"

Light::Light(Color lightColor, Vector3 lightPos)
        : lightColor(lightColor.r, lightColor.g, lightColor.b, lightColor.a),
          lightPos(lightPos.x, lightPos.y, lightPos.z)
{}

glm::vec4 Light::getLightColor()
{
    return lightColor;
}

glm::vec3 Light::getLightPos()
{
    return lightPos;
}
