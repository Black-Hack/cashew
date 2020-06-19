#include "glfw.hpp"

#include <GLFW/glfw3.h>

#include "glfw_error.hpp"

glfw glfw::singleton;

glfw::glfw()
{
	glfwInit();
	throw_if_error();
}

void glfw::throw_if_error() {
	const char* description;
	if (glfwGetError(&description)) {
		throw glfw_error(description);
	}
}

void glfw::update()
{
	glfwPollEvents();
	throw_if_error();
}

glfw::~glfw()
{
	glfwTerminate();
	throw_if_error();
}
