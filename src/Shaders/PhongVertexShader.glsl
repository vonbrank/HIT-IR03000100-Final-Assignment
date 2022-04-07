#version 330

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec3 aNormal;

out vec3 Normal;
out vec3 FragmentPos;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main() {
    gl_Position = projection * view * model *  vec4(aPos, 1.0);
    Normal = mat3(transpose(inverse(model))) * aNormal;
    FragmentPos = vec3(model * vec4(aPos, 1.0f));
    texCoord = aTexCoord;
}
