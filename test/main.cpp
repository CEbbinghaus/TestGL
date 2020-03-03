#include <gl_core_4_5.h>
#include <glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "./Dependencies/stbi/stb_image.h"
#include <crtdbg.h>
#include <iostream>

//#include <atyp_Matrix4.h>

#include "Shader.h"
#include "Mesh.h"
#include "Primitive.h"

using uint = unsigned int;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (glfwInit() == false)
		return -1;

	GLFWwindow *window = glfwCreateWindow(1000, 1000, "TestBed", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("Running OpenGL Version %i.%i\n", major, minor);

	glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

	Shader shader = Shader();
	shader.LoadShader("./Shaders/FragShader.frag", Shader::Type::Frag);
	shader.LoadShader("./Shaders/VertShader.vert", Shader::Type::Vertex);
	shader.CompileShader();
	glUseProgram(shader.ProgrammID);

	Mesh m = Primitive::Sphere(50, 50);














	// GLuint bindingPoint = 1, buffer, blockIndex;
	// float myFloats[8] = {1.0, 0.0, 1.0, 1.0, 0.4, 0.0, 0.0, 1.0};

	// blockIndex = glGetUniformBlockIndex(shader.ProgrammID, "ColorBlock");
	// glUniformBlockBinding(shader.ProgrammID, blockIndex, bindingPoint);

	// glGenBuffers(1, &buffer);
	// glBindBuffer(GL_UNIFORM_BUFFER, buffer);

	// glBufferData(GL_UNIFORM_BUFFER, sizeof(myFloats), myFloats, GL_DYNAMIC_DRAW);
	// glBindBufferBase(GL_UNIFORM_BUFFER, bindingPoint, buffer);





	float data[] = {.0f, .5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
	GLuint UniformBlockIndex, buffer;
	GLint bindIndex = 1, UniformBufferSize;

	UniformBlockIndex = glGetUniformBlockIndex(shader.ProgrammID, "ColorBlock");
	glGetActiveUniformBlockiv(shader.ProgrammID, UniformBlockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &UniformBufferSize);
	glUniformBlockBinding(shader.ProgrammID, UniformBlockIndex, bindIndex);

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_UNIFORM_BUFFER, buffer);
	
	glBufferData(GL_UNIFORM_BUFFER, UniformBufferSize, data, GL_STATIC_DRAW);
	glBindBufferRange(GL_UNIFORM_BUFFER, bindIndex, buffer, 0, sizeof(data));











	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();

		m.draw();

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

/*
	float data[] = {.0f, .0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
	GLuint UniformBlockIndex;
	GLint bindIndex = 1, UniformBufferSize;

	UniformBlockIndex = glGetUniformBlockIndex(shader.ProgrammID, "testing");
	glGetActiveUniformBlockiv(shader.ProgrammID, UniformBlockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &UniformBufferSize);
	glGetActiveUniformBlockiv(shader.ProgrammID, UniformBlockIndex, GL_UNIFORM_BLOCK_BINDING, &bindIndex);
	glUniformBlockBinding(shader.ProgrammID, UniformBlockIndex, bindIndex);

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBufferRange(GL_UNIFORM_BUFFER, bindIndex, buffer, 0, sizeof(data));
	glBindBuffer(GL_UNIFORM_BUFFER, buffer);
	glBufferData(GL_UNIFORM_BUFFER, 8, data, GL_STATIC_DRAW);
	
	printf("Uniform Buffer is %i Bytes Long.\n", UniformBufferSize);
	*/