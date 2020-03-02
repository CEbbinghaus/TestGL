#version 450

in vec3 position;
in vec2 TexCoord;
in vec3 normal;
in vec3 color;

out vec4 FragColor;

void main(){
    FragColor = vec4(position, 1);
}