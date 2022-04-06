//
// Created by VonBrank on 2022/4/6.
//

#include "Cube.h"
#include "../Utils/TextureLoader.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

Cube::Cube(float edgeLength, const Shader &shader) : edgeLength(edgeLength), SpriteRenderer(shader) {

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

    vertices[0].x = -edgeLength / 2;
    vertices[0].y = edgeLength / 2;
    vertices[0].z = edgeLength / 2;
    vertices[0].w = 1;
    texCoords[0].x = 0;
    texCoords[0].y = 1;

    vertices[1].x = edgeLength / 2;
    vertices[1].y = edgeLength / 2;
    vertices[1].z = edgeLength / 2;
    vertices[1].w = 1;
    texCoords[1].x = 1;
    texCoords[1].y = 1;

    vertices[2].x = edgeLength / 2;
    vertices[2].y = -edgeLength / 2;
    vertices[2].z = edgeLength / 2;
    vertices[2].w = 1;
    texCoords[2].x = 1;
    texCoords[2].y = 0;

    vertices[3].x = -edgeLength / 2;
    vertices[3].y = -edgeLength / 2;
    vertices[3].z = edgeLength / 2;
    vertices[3].w = 1;
    texCoords[3].x = 0;
    texCoords[3].y = 0;

    vertices[4].x = -edgeLength / 2;
    vertices[4].y = edgeLength / 2;
    vertices[4].z = -edgeLength / 2;
    vertices[4].w = 1;
    texCoords[4].x = 0;
    texCoords[4].y = 0;

    vertices[5].x = edgeLength / 2;
    vertices[5].y = edgeLength / 2;
    vertices[5].z = -edgeLength / 2;
    vertices[5].w = 1;
    texCoords[5].x = 1;
    texCoords[5].y = 0;

    vertices[6].x = edgeLength / 2;
    vertices[6].y = -edgeLength / 2;
    vertices[6].z = -edgeLength / 2;
    vertices[6].w = 1;
    texCoords[6].x = 1;
    texCoords[6].y = 1;

    vertices[7].x = -edgeLength / 2;
    vertices[7].y = -edgeLength / 2;
    vertices[7].z = -edgeLength / 2;
    vertices[7].w = 1;
    texCoords[7].x = 0;
    texCoords[7].y = 1;

    lengthOfVertexAttribute = 5;
    lengthOfVertices = lengthOfVertexAttribute * 8;
    verticesBuffer = new float[lengthOfVertices];


    for (int i = 0; i < 8; i++) {
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

    indices = new unsigned int[6]{
            0, 1, 3,
            1, 2, 3
//            4, 5, 7,
//            5, 6, 7
    };

    glBufferData(GL_ARRAY_BUFFER, lengthOfVertices * sizeof(float), verticesBuffer, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, lengthOfVertexAttribute * sizeof(float), (void *) 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, lengthOfVertexAttribute * sizeof(float),
                          (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


}

void Cube::draw() {
    SpriteRenderer::draw();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Cube::~Cube() {
    delete[] verticesBuffer;
    delete[] indices;
}