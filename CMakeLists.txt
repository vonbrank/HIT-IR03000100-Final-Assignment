cmake_minimum_required(VERSION 3.21)
project(Sphere_Shading)

set(CMAKE_CXX_STANDARD 14)

link_directories("lib/bin")
include_directories("lib/include")

add_executable(Sphere_Shading src/main.cpp src/OpenGLContainer.cpp lib/cpp/glad.c src/MonoBehaviour.cpp src/MonoBehaviour.h)
target_link_libraries(Sphere_Shading libglfw3.a)