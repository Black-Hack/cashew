#include "glfw.hpp"

#include <GLFW/glfw3.h>

#include "glfw_error.hpp"

glfw glfw::singleton;

glfw::glfw()
{
	glfwSetErrorCallback([](int code, const char* description) {
		throw glfw_error(code, description);
	});

	glfwInit();
}

void glfw::update()
{
	glfwPollEvents();
}

glfw::~glfw()
{
	glfwTerminate();
}
