//
// Created by VonBrank on 2022/4/6.
//

#ifndef SPHERE_SHADING_SPRITERENDERER_H
#define SPHERE_SHADING_SPRITERENDERER_H

#include "MonoBehaviour.h"
#include "../Utils/Vector.hpp"
#include "../OpenGLContainer.h"
#include "../Utils/Shader.h"

class SpriteRenderer : public MonoBehaviour {
protected:
    float *verticesBuffer;
    unsigned long long lengthOfVertices;
    unsigned long long lengthOfVertexAttribute;
    Shader shader;
    unsigned int VAO, VBO, EBO;
public:
    explicit SpriteRenderer(const Shader& shader);
    void update() override;
    virtual void draw();
};


#endif //SPHERE_SHADING_SPRITERENDERER_H
