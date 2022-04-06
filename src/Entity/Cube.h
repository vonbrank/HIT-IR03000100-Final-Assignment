//
// Created by VonBrank on 2022/4/6.
//

#ifndef SPHERE_SHADING_CUBE_H
#define SPHERE_SHADING_CUBE_H

#include "SpriteRenderer.h"
#include <array>
#include "../Utils/Vector.hpp"
#include "../Utils/Color.hpp"

class Cube : public SpriteRenderer {
private:
    std::array<Vector4, 8> vertices;
    std::array<Color, 8> verticesColor;
    std::array<Vector2, 8> texCoords;
    float edgeLength;
    unsigned int *indices;
    Color color;
    unsigned int texture1, texture2;
    unsigned int LengthOfelementArrayBuffer;
    float angle;


public:
    Cube(const Cube &cube) = delete;
    Cube operator=(const Cube &cube) = delete;
    void render() override;
    Cube(float edgeLength, const Shader& shader);
//    void processInput(GLFWwindow* window) override;
    void update() override;
    ~Cube();

};


#endif //SPHERE_SHADING_CUBE_H
