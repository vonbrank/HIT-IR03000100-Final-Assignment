//
// Created by VonBrank on 2022/4/5.
//

#ifndef SPHERE_SHADING_COLOR_HPP
#define SPHERE_SHADING_COLOR_HPP

struct Color {
    float r;
    float g;
    float b;
    float a;

    Color() : r(0.0), g(0.0), b(0.0), a(0.0) {}

    Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
};

#endif //SPHERE_SHADING_COLOR_HPP
