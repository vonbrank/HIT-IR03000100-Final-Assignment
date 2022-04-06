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

int main() {
    OpenGLContainer openGlContainer(SCR_WIDTH, SCR_HEIGHT, WINDOW_TITLE);

    Shader defaultShader(
            "D:\\Users\\VonBrank\\Documents\\Source\\Repos\\Github\\Personal\\HIT-IR03000100-Final-Assignment\\src\\Shaders\\DefaultVertexShader.glsl",
            "D:\\Users\\VonBrank\\Documents\\Source\\Repos\\Github\\Personal\\HIT-IR03000100-Final-Assignment\\src\\Shaders\\DefaultFragmentShader.glsl");

    Shader cubeShader(
            "D:\\Users\\VonBrank\\Documents\\Source\\Repos\\Github\\Personal\\HIT-IR03000100-Final-Assignment\\src\\Shaders\\CubeVertexShader.glsl",
            "D:\\Users\\VonBrank\\Documents\\Source\\Repos\\Github\\Personal\\HIT-IR03000100-Final-Assignment\\src\\Shaders\\CubeFragmentShader.glsl"
    );
//    auto *triangle = new Triangle(std::array<Vector4, 3>{
//                              (Vector4) {-0.5f, -0.5f, 0.0f},
//                              (Vector4) {0.5f, -0.5f, 0.0f},
//                              (Vector4) {0.0f, 0.5f, 0.0f},
//                      },
//                      std::array<Color, 3>{
//                              (Color) {1, 1, 1, 1},
//                              (Color) {1, 1, 1, 1},
//                              (Color) {1, 1, 1, 1},
//                      },
//                      defaultShader);

    auto *cube = new Cube(1, cubeShader);

    openGlContainer.addSpriteRenderer(cube);
    openGlContainer.run();

    return 0;
}
