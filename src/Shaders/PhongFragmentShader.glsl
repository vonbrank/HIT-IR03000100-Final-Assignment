#version 330

in vec3 Normal;
in vec3 FragmentPos;
in vec2 texCoord;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec4 lightColor;
uniform vec3 viewPos;
uniform sampler2D texture1;
uniform sampler2D texture2;


void main() {
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * vec3(lightColor.xyz);
//    vec3 objectColor = vec3(1.0f, 0.5f, 0.2f);
    vec2 localTexCoord = texCoord;
    vec3 objectColor = (mix(texture(texture1, localTexCoord), texture(texture2, localTexCoord), 0.5f)).xyz;


    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragmentPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor.xyz;

    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragmentPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float shininess = 128;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * lightColor.xyz;

    vec3 result = (ambient + diffuse + specular) * objectColor;
//    vec3 result = (specular) * objectColor;

    FragColor = vec4(result, 1.0);
}
