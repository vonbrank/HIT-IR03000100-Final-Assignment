//
// Created by VonBrank on 2022/4/6.
//

#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(const Shader &shader) : shader(shader) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void SpriteRenderer::draw() {
    shader.use();
    glBindVertexArray(VAO);
}

void SpriteRenderer::update() {
    draw();
}