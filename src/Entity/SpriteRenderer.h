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
#include "Light.h"

class SpriteRenderer : public MonoBehaviour
{
protected:
    float *verticesBuffer;
    unsigned long long lengthOfVertices;    //顶点缓存中存储的顶点的数量
    unsigned long long lengthOfVertexAttribute; //顶点缓存数组中每个顶点属性所占的长度
    unsigned long long lengthOfVerticesBuffer;  //顶点缓存数组的总长度
    Shader shader;
    unsigned int VAO, VBO, EBO;
    Camera *cameraPointer;
    Light *lightPointer;
    glm::mat4 model;

public:
    explicit SpriteRenderer(const Shader &shader);

    void update() override;
    virtual void render();
    void setCameraPointer(Camera* cameraPointer);
    void setLightPointer(Light* lightPointer);
};


#endif //SPHERE_SHADING_SPRITERENDERER_H
