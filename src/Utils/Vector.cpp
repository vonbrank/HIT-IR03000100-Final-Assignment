//
// Created by VonBrank on 2022/4/9.
//

#include "Vector.hpp"

Vector2 operator+(const Vector2 &a, const Vector2 &b)
{
    return {a.x + b.x, a.y + b.y};
}

Vector2 operator/(const Vector2 &a, float b)
{
    return {a.x / b, a.y / b};
}