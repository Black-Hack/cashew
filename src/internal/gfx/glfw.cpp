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

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
}

void glfw::update()
{
	glfwPollEvents();
}

glfw::~glfw()
{
	glfwTerminate();
}
