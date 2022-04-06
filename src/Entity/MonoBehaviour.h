//
// Created by VonBrank on 2022/4/5.
//

#ifndef SPHERE_SHADING_MONOBEHAVIOUR_H
#define SPHERE_SHADING_MONOBEHAVIOUR_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class MonoBehaviour {
public:
    float* deltaTimePointer;

    virtual void start();
    virtual void awake();
    virtual void update();
    virtual void processInput(GLFWwindow* window);
};


#endif //SPHERE_SHADING_MONOBEHAVIOUR_H
