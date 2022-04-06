//
// Created by VonBrank on 2022/4/6.
//

#ifndef SPHERE_SHADING_SPRITERENDERER_H
#define SPHERE_SHADING_SPRITERENDERER_H

#include "MonoBehaviour.h"
#include "../Utils/Vector.hpp"
#include "../Utils/Shader.h"
#include "Camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class SpriteRenderer : public MonoBehaviour
{
protected:
    float *verticesBuffer;
    unsigned long long lengthOfVertices;
    unsigned long long lengthOfVertexAttribute;
    Shader shader;
    unsigned int VAO, VBO, EBO;
    Camera *cameraPointer;
    glm::mat4 model;

public:
    explicit SpriteRenderer(const Shader &shader);

    void update() override;
    virtual void render();
    void setCameraPointer(Camera* cameraPointer);
};


#endif //SPHERE_SHADING_SPRITERENDERER_H
