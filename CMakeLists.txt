cmake_minimum_required(VERSION 3.21)
project(Sphere_Shading)

set(CMAKE_CXX_STANDARD 14)

link_directories("lib/bin")
include_directories("lib/include")

add_executable(
        Sphere_Shading
        src/main.cpp
        src/OpenGLContainer.cpp
        lib/cpp/glad.c
        src/Entity/Triangle.cpp
        src/Entity/Triangle.h
        src/Utils/Vector.hpp
        src/Entity/MonoBehaviour.cpp
        src/Entity/MonoBehaviour.h
        src/Utils/Shader.cpp
        src/Utils/TextureLoader.cpp
        src/Utils/Utils.cpp
        src/Entity/SpriteRenderer.cpp
        src/Entity/Cube.cpp
        src/Entity/Camera.cpp
        src/Entity/Camera.h src/Entity/Light.cpp src/Entity/Light.h src/Entity/Sphere.cpp src/Entity/Sphere.h src/DataModel/InputDataModel.hpp src/Utils/Vector.cpp)
target_link_libraries(Sphere_Shading libglfw3.a)

execute_process(COMMAND ${CMAKE_COMMAND} -E
        copy_directory ${CMAKE_SOURCE_DIR}/Images/ ${CMAKE_BINARY_DIR}/Images/
        )
execute_process(COMMAND ${CMAKE_COMMAND} -E
        copy_directory ${CMAKE_SOURCE_DIR}/src/Shaders/ ${CMAKE_BINARY_DIR}/Shaders/
        )