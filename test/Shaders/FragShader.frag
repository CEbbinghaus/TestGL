#version 450

uniform ColorBlock {
    vec4 diffuse;
    vec4 ambient;
};

in vec3 position;
in vec2 TexCoord;
in vec3 normal;
in vec3 color;

out vec4 FragColor;

void main(){
    FragColor = ambient;
}