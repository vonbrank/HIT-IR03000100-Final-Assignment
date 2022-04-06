#version 330 core

in vec2 texCoord;
out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    vec2 localTexCoord = texCoord;
    FragColor = mix(texture(texture1, localTexCoord), texture(texture2, localTexCoord), 0.5f);
//    FragColor = texture(texture2, localTexCoord);
}