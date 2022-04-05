//
// Created by VonBrank on 2022/4/5.
//

#ifndef SPHERE_SHADING_VECTOR_HPP
#define SPHERE_SHADING_VECTOR_HPP

struct Vector4 {
    float x;
    float y;
    float z;
    float w;

    Vector4() : x(0), y(0), z(0), w(1) {}

    Vector4(float x, float y, float z) : x(x), y(y), z(z), w(1) {}

    Vector4(float x, float y, float z, float w) : x(x / w), y(y / w), z(z / w), w(1) {}
};

#endif //SPHERE_SHADING_VECTOR_HPP
