//
// Created by VonBrank on 2022/3/31.
//

#ifndef OPENGL_LEARNING_CMAKE_SHADER_H
#define OPENGL_LEARNING_CMAKE_SHADER_H

#include "glad/glad.h"

#include <string>
#include <fstream>
#include <iostream>

class Shader {
public:
    unsigned int ID;
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};


#endif //OPENGL_LEARNING_CMAKE_SHADER_H
