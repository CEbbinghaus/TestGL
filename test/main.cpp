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

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (glfwInit() == false)
		return -1;

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "TestBed", nullptr, nullptr);

	if (window == nullptr) {
		glfwTerminate(); return -2;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("Running OpenGL Version %i.%i\n", major, minor);

	glClearColor(0.1f, 0.1f, 0.2f, 1.0f);


	//glfwWindowShouldClose(window) == 1 && 
	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}