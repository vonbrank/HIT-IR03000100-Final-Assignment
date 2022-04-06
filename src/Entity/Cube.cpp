//
// Created by VonBrank on 2022/4/6.
//

#include "Cube.h"
#include "../Utils/TextureLoader.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

Cube::Cube(float edgeLength, const Shader &shader) : edgeLength(edgeLength), SpriteRenderer(shader)
{

    glGenTextures(1, &texture1);
    glGenTextures(1, &texture2);

    glBindTexture(GL_TEXTURE_2D, texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    TextureLoader::load("..\\Images\\container.jpg");

    stbi_set_flip_vertically_on_load(true);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    TextureLoader::load("..\\Images\\awesomeface.png", GL_RGBA);

    this->shader.use();
    this->shader.setInt("texture1", 0);
    this->shader.setInt("texture2", 1);

    int verticesSigned[][5] =
            {
                    {-1, 1,  1,  0, 1},
                    {1,  1,  1,  1, 1},
                    {1,  -1, 1,  1, 0},
                    {-1, -1, 1,  0, 0},
                    {-1, 1,  -1, 0, 1},
                    {1,  1,  -1, 0, 0},
                    {1,  -1, -1, 1, 0},
                    {-1, -1, -1, 1, 1},
            };

    for (int i = 0; i < 8; i++)
    {
        vertices[i].x = verticesSigned[i][0] * edgeLength / 2;
        vertices[i].y = verticesSigned[i][1] * edgeLength / 2;
        vertices[i].z = verticesSigned[i][2] * edgeLength / 2;
        vertices[i].w = 1;
        texCoords[i].x = verticesSigned[i][3];
        texCoords[i].y = verticesSigned[i][4];
    }

    lengthOfVertexAttribute = 5;
    lengthOfVertices = lengthOfVertexAttribute * 8;
    verticesBuffer = new float[lengthOfVertices];

    for (int i = 0; i < 8; i++)
    {
        int startIndex = i * lengthOfVertexAttribute;
        verticesBuffer[startIndex] = vertices[i].x;
        verticesBuffer[startIndex + 1] = vertices[i].y;
        verticesBuffer[startIndex + 2] = vertices[i].z;
        verticesBuffer[startIndex + 3] = texCoords[i].x;
        verticesBuffer[startIndex + 4] = texCoords[i].y;
    }

//    for (int i = 0; i < lengthOfVertices; i++) {
//        std::cout << verticesBuffer[i] << " ";
//    }
//    std::cout << std::endl;

    LengthOfelementArrayBuffer = 36;

    indices = new unsigned int[LengthOfelementArrayBuffer]{
            0, 1, 3,
            1, 2, 3,
            4, 0, 7,
            0, 3, 7,
            1, 5, 2,
            5, 6, 2,
            5, 4, 6,
            4, 7, 6,
            4, 5, 0,
            5, 1, 0,
            3, 2, 7,
            2, 6, 7
    };

    glBufferData(GL_ARRAY_BUFFER, lengthOfVertices * sizeof(float), verticesBuffer, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, LengthOfelementArrayBuffer * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, lengthOfVertexAttribute * sizeof(float), (void *) 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, lengthOfVertexAttribute * sizeof(float),
                          (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    angle = 45.0f;
    model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.5f, 1.0f, 1.0f));
}

void Cube::render()
{
    SpriteRenderer::render();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glDrawElements(GL_TRIANGLES, LengthOfelementArrayBuffer, GL_UNSIGNED_INT, 0);
}

void Cube::update()
{
    angle += (*deltaTimePointer) * 50;
    model = glm::rotate(glm::mat4(1.0f),  glm::radians(angle), glm::vec3(0.5f, 1.0f, 1.0f));
    SpriteRenderer::update();
}

Cube::~Cube()
{
    delete[] verticesBuffer;
    delete[] indices;
}