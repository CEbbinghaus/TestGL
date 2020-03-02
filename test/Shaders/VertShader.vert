#version 450

layout(location = 0) in vec3 VertPos;
layout(location = 1) in vec3 VertNormal;
layout(location = 2) in vec2 VertUV;

out vec3 normal;
out vec3 color;
out vec2 TexCoord;
out vec3 position;

void main(){
	gl_Position = vec4(VertPos, 1);
	normal = normalize((vec4(VertNormal, 0)).xyz);
	color = vec3(1);
	TexCoord = VertUV;
	position = gl_Position.xyz;
}