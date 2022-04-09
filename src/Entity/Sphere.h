//
// Created by VonBrank on 2022/4/7.
//

#ifndef SPHERE_SHADING_SPHERE_H
#define SPHERE_SHADING_SPHERE_H

#include "SpriteRenderer.h"
#include <vector>
#include "../Utils/Vector.hpp"

class Sphere : public SpriteRenderer
{
private:
    float radius;
    int numOfLongitudeSection;
    int numOfLatitudeSection;
    std::vector<std::vector<Vector3>> keyCoords;
    std::vector<std::vector<Vector3>> normals;
    std::vector<std::vector<Vector2>> texCoords;
    unsigned int texture1{}, texture2{}, texture3{};
    float verticalRotationSpeed;
    float verticalRotationSpeedAttenuationCoefficient;
    glm::vec2 cloudOffset{};
    float cloudOffsetSpeed;
    bool lineMode = false;
    bool keyLTrigger = false;

    static void mouse_callback(GLFWwindow *window, int button, int action, int mods);
public:
    float angle;
    Sphere(float radius, const Shader &shader);

    void render() override;

    void setVerticesBufferAttributes(float *arr, int index, Vector3 vertices, Vector2 texCoord, Vector3 normal);

    void update() override;

    void processInput(GLFWwindow *window) override;

};


#endif //SPHERE_SHADING_SPHERE_H
