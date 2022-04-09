//
// Created by VonBrank on 2022/4/7.
//

#include "Sphere.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "../Utils/TextureLoader.h"
#include "../Utils/Utils.h"

Sphere::Sphere(float radius, const Shader &shader)
        : radius(radius), SpriteRenderer(shader), numOfLongitudeSection(24),
          numOfLatitudeSection(numOfLongitudeSection * 2)
{

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    TextureLoader::load(
            ".\\Images\\2k_earth_daymap.jpg");


    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    TextureLoader::load(
            ".\\Images\\2k_earth_nightmap.jpg");


    glGenTextures(1, &texture3);
    glBindTexture(GL_TEXTURE_2D, texture3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    TextureLoader::load(
            ".\\Images\\2k_earth_clouds.jpg");


    this->shader.use();
    this->shader.setInt("texture1", 0);
    this->shader.setInt("texture2", 1);
    this->shader.setInt("texture3", 2);


    float lengthOfLongitudeSection = 1.0 / numOfLongitudeSection;
    float lengthOfLatitudeSection = lengthOfLongitudeSection;
    keyCoords = std::vector<std::vector<Vector3>>(numOfLongitudeSection + 1);
    normals = std::vector<std::vector<Vector3>>(numOfLongitudeSection + 1);
    texCoords = std::vector<std::vector<Vector2>>(numOfLongitudeSection + 1);

    for (int i = 0; i <= numOfLongitudeSection; i++)
    {
        keyCoords[i].resize(numOfLatitudeSection + 1);
        normals[i].resize(numOfLatitudeSection + 1);
        texCoords[i].resize(numOfLatitudeSection + 1);

        for (int j = 0; j <= numOfLatitudeSection; j++)
        {
            float theta = lengthOfLongitudeSection * i * 180;
            float phi = lengthOfLatitudeSection * j * 180 + 270;
            keyCoords[i][j].x = sin(glm::radians(theta)) * cos(glm::radians(phi));
            keyCoords[i][j].z = sin(glm::radians(theta)) * sin(glm::radians(phi));
            keyCoords[i][j].y = cos(glm::radians(theta));
            texCoords[i][j].x = 1 - lengthOfLatitudeSection * j / 2;
            texCoords[i][j].y = 1 - lengthOfLongitudeSection * i;
//            std::cout << "[" << keyCoords[i][j].x << ", " << keyCoords[i][j].z << ", " << keyCoords[i][j].y << "] ";
//            std::cout << "[" << texCoords[i][j].x << ", " << texCoords[i][j].y << "] ";
        }
//        std::cout << std::endl;
    }

    lengthOfVertexAttribute = 8;
    lengthOfVertices = 6 * numOfLatitudeSection * (numOfLongitudeSection - 1);
    lengthOfVerticesBuffer = lengthOfVertexAttribute * lengthOfVertices;
    verticesBuffer = new float[lengthOfVerticesBuffer];

    int startIndex = 0;

    for (int i = 0; i < numOfLatitudeSection; i++)
    {
        setVerticesBufferAttributes(verticesBuffer, startIndex, keyCoords[1][i],
                                    texCoords[1][i], keyCoords[1][i]);

        setVerticesBufferAttributes(verticesBuffer, startIndex + 8, keyCoords[1][i + 1],
                                    texCoords[1][i + 1], keyCoords[1][i + 1]);

        setVerticesBufferAttributes(verticesBuffer, startIndex + 16, keyCoords[0][i],
                                    (texCoords[0][i] + texCoords[0][i + 1]) / 2, keyCoords[0][i]);

        setVerticesBufferAttributes(verticesBuffer, startIndex + 24, keyCoords[numOfLongitudeSection - 1][i],
                                    texCoords[numOfLongitudeSection - 1][i], keyCoords[numOfLongitudeSection - 1][i]);

        setVerticesBufferAttributes(verticesBuffer, startIndex + 32, keyCoords[numOfLongitudeSection - 1][i + 1],
                                    texCoords[numOfLongitudeSection - 1][i + 1],
                                    keyCoords[numOfLongitudeSection - 1][i + 1]);

        setVerticesBufferAttributes(verticesBuffer, startIndex + 40, keyCoords[numOfLongitudeSection][i],
                                    (texCoords[numOfLongitudeSection][i] + texCoords[numOfLongitudeSection][i + 1]) / 2,
                                    keyCoords[numOfLongitudeSection][i]);
//        std::cout << "[" << texCoords[1][i].x << ", " << texCoords[1][i + 1].y << "]" << ", "
//                  << "[" << texCoords[1][i + 1].x << "," << texCoords[1][i + 1].y << "]" << std::endl;
        startIndex += 48;

    }

    for (int i = 1; i <= numOfLongitudeSection - 2; i++)
    {
        for (int j = 0; j < numOfLatitudeSection; j++)
        {
            setVerticesBufferAttributes(verticesBuffer, startIndex, keyCoords[i][j],
                                        texCoords[i][j], keyCoords[i][j]);

            setVerticesBufferAttributes(verticesBuffer, startIndex + 8, keyCoords[i][j + 1],
                                        texCoords[i][j + 1], keyCoords[i][j + 1]);

            setVerticesBufferAttributes(verticesBuffer, startIndex + 16, keyCoords[i + 1][j],
                                        texCoords[i + 1][j], keyCoords[i + 1][j]);

            setVerticesBufferAttributes(verticesBuffer, startIndex + 24, keyCoords[i][j + 1],
                                        texCoords[i][j + 1], keyCoords[i][j + 1]);

            setVerticesBufferAttributes(verticesBuffer, startIndex + 32, keyCoords[i + 1][j + 1],
                                        texCoords[i + 1][j + 1], keyCoords[i + 1][j + 1]);

            setVerticesBufferAttributes(verticesBuffer, startIndex + 40, keyCoords[i + 1][j],
                                        texCoords[i + 1][j], keyCoords[i + 1][j]);

            startIndex += 48;
        }
    }

    glBufferData(GL_ARRAY_BUFFER, lengthOfVerticesBuffer * sizeof(float), verticesBuffer, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, lengthOfVertexAttribute * sizeof(float), (void *) 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, lengthOfVertexAttribute * sizeof(float),
                          (void *) (3 * sizeof(float)));
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, lengthOfVertexAttribute * sizeof(float),
                          (void *) (5 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    angle = 60.0f;
    model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
    verticalRotationSpeed = 0.0f;
    verticalRotationSpeedAttenuationCoefficient = 360.0f;
    cloudOffsetSpeed = -0.005;
    cloudOffset = glm::vec2(0, 0);

}

void Sphere::render()
{
    SpriteRenderer::render();
    int cloudOffsetLoc = glGetUniformLocation(shader.ID, "cloudOffset");
//    std::cout << cloudOffsetLoc << std::endl;
    if (cloudOffsetLoc != -1) glUniform2fv(cloudOffsetLoc, 1, glm::value_ptr(cloudOffset));
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, texture3);
    if (lineMode)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays(GL_TRIANGLES, 0, lengthOfVertices);
}

void Sphere::setVerticesBufferAttributes(float *arr, int index, Vector3 vertices, Vector2 texCoord, Vector3 normal)
{
    arr[index] = vertices.x;
    arr[index + 1] = vertices.y;
    arr[index + 2] = vertices.z;
    arr[index + 3] = texCoord.x;
    arr[index + 4] = texCoord.y;
    arr[index + 5] = normal.x;
    arr[index + 6] = normal.y;
    arr[index + 7] = normal.z;
}

void Sphere::update()
{
//    std::cout << "Before Sphere update" << angle << std::endl;

    Utils::linearAttenuation(verticalRotationSpeed, verticalRotationSpeedAttenuationCoefficient, *deltaTimePointer);
//    std::cout << "Before Sphere update: " << verticalRotationSpeed << std::endl;
    angle += verticalRotationSpeed * (*deltaTimePointer);
    model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
    cloudOffset = glm::vec2(cloudOffset.x + cloudOffsetSpeed * (*deltaTimePointer), 0);

//    std::cout << "After Sphere update" << angle << std::endl;
//    std::cout << cloudOffsetSpeed * (*deltaTimePointer) << std::endl;
    SpriteRenderer::update();
}


void Sphere::processInput(GLFWwindow *window)
{
    if (inputDataModel->leftButtonDown)
    {
        verticalRotationSpeed = inputDataModel->mouseMoveSpeedPercentageX * 180;
    }
    if (glfwGetKey(window, GLFW_KEY_L) && !keyLTrigger)
    {
        keyLTrigger = true;
    }
    else if(!glfwGetKey(window, GLFW_KEY_L) && keyLTrigger)
    {
        keyLTrigger = false;
        lineMode ^= 1;
    }

}