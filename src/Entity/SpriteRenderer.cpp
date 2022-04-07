//
// Created by VonBrank on 2022/4/6.
//

#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(const Shader &shader) : shader(shader), model(glm::mat4(1.0f))
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void SpriteRenderer::render()
{
    shader.use();
    glBindVertexArray(VAO);
    int modelLoc = glGetUniformLocation(shader.ID, "model");
    int viewLoc = glGetUniformLocation(shader.ID, "view");
    int projectionLoc = glGetUniformLocation(shader.ID, "projection");
    int lightPosLoc = glGetUniformLocation(shader.ID, "lightPos");
    int lightColorLoc = glGetUniformLocation(shader.ID, "lightColor");
    int viewPosLoc = glGetUniformLocation(shader.ID, "viewPos");
    if (modelLoc != -1) glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    if (viewLoc != -1) glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(cameraPointer->getView()));
    if (viewLoc != -1) glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(cameraPointer->getProjection()));
    if (lightPosLoc != -1) glUniform3fv(lightPosLoc, 1, glm::value_ptr(lightPointer->getLightPos()));
    if (lightColorLoc != -1) glUniform4fv(lightColorLoc, 1, glm::value_ptr(lightPointer->getLightColor()));
    if (viewPosLoc != -1) glUniform3fv(viewPosLoc, 1, glm::value_ptr(cameraPointer->getViewPos()));
}

void SpriteRenderer::update()
{
    render();
}

void SpriteRenderer::setCameraPointer(Camera *cameraPointer)
{
    this->cameraPointer = cameraPointer;
}

void SpriteRenderer::setLightPointer(Light *lightPointer)
{
    this->lightPointer = lightPointer;
}