//
// Created by VonBrank on 2022/4/5.
//

#ifndef SPHERE_SHADING_TRIANGLE_H
#define SPHERE_SHADING_TRIANGLE_H

#include <vector>
#include "../Utils/Vector.hpp"
#include "../OpenGLContainer.h"
#include "../Utils/Shader.h"
#include "SpriteRenderer.h"
#include <array>

class Triangle : public SpriteRenderer {
private:
    std::array<Vector4, 3> vertices;
    std::array<Color, 3> verticesColor;
    Triangle operator=(const Triangle &triangle);
    Triangle(const Triangle &triangle);
public:
    Triangle(const std::array<Vector4, 3> &vertices, const std::array<Color, 3> &verticesColor, Shader &shader);
    void draw() override;

    ~Triangle();
};


#endif //SPHERE_SHADING_TRIANGLE_H
