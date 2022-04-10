#include <iostream>

#include "OpenGLContainer.h"

//#define STB_IMAGE_IMPLEMENTATION
//
//#include "stb_image.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Config.hpp"
#include "Entity/Triangle.h"
#include "Entity/Cube.h"
#include "Utils/Shader.h"
#include "Entity/Sphere.h"

int main()
{
    OpenGLContainer openGlContainer(SCR_WIDTH, SCR_HEIGHT, WINDOW_TITLE);

    Shader defaultShader(
            ".\\Shaders\\DefaultVertexShader.glsl",
            ".\\Shaders\\DefaultFragmentShader.glsl");

    Shader cubeShader(
            ".\\Shaders\\CubeVertexShader.glsl",
            ".\\Shaders\\CubeFragmentShader.glsl"
    );

    Shader phongShader(
            ".\\Shaders\\PhongVertexShader.glsl",
            ".\\Shaders\\PhongFragmentShader.glsl"
    );

    auto *cube = new Cube(0.5, phongShader);
    auto *sphere = new Sphere(1, phongShader);

    openGlContainer.anglePointer = &(sphere->angle);

    openGlContainer.addSpriteRenderer(cube);
    openGlContainer.addSpriteRenderer(sphere);
    openGlContainer.run();

    return 0;
}
