//
// Created by VonBrank on 2022/4/5.
//

#include "Triangle.h"

Triangle::Triangle(const std::array<Vector4, 3> &vertices, const std::array<Color, 3> &verticesColor, Shader &shader) :
        vertices(vertices), verticesColor(verticesColor), SpriteRenderer(shader) {

    lengthOfVertexAttribute = 6;
    lengthOfVertices = lengthOfVertexAttribute * 3;
    verticesBuffer = new float[lengthOfVertices];

    for (int i = 0; i < 3; i++) {
        int startIndex = i * lengthOfVertexAttribute;
        verticesBuffer[startIndex] = vertices[i].x;
        verticesBuffer[startIndex + 1] = vertices[i].y;
        verticesBuffer[startIndex + 2] = vertices[i].z;
        verticesBuffer[startIndex + 3] = verticesColor[i].r;
        verticesBuffer[startIndex + 4] = verticesColor[i].g;
        verticesBuffer[startIndex + 5] = verticesColor[i].b;
//        std::cout << verticesBuffer[startIndex] << " "
//                  << verticesBuffer[startIndex + 1] << " "
//                  << verticesBuffer[startIndex + 2] << " "
//                  << verticesBuffer[startIndex + 3] << " "
//                  << verticesBuffer[startIndex + 4] << " "
//                  << verticesBuffer[startIndex + 5] << std::endl;
    }


    glBufferData(GL_ARRAY_BUFFER, lengthOfVertices * sizeof(float), verticesBuffer, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, lengthOfVertexAttribute * sizeof(float), (void *) 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, lengthOfVertexAttribute * sizeof(float),
                          (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
}

Triangle::Triangle(const Triangle &triangle): SpriteRenderer(triangle.shader) {}

void Triangle::draw() {
    SpriteRenderer::draw();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

Triangle Triangle::operator=(const Triangle &triangle) { return *this; }



Triangle::~Triangle() {
    delete[] verticesBuffer;
}
