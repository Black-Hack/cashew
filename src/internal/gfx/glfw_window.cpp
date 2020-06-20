#include "glfw_window.hpp"

#include <GLFW/glfw3.h>

#include "glfw.hpp"

glfw_window::glfw_window(int width, int height, const char* title) :
	window(glfwCreateWindow(width, height, title, nullptr, nullptr))
{
	glfw::throw_if_error();
}

bool glfw_window::close_requested() const
{
	auto res = glfwWindowShouldClose(window);
	glfw::throw_if_error();
	return res;
}

void glfw_window::make_context_current()
{
	glfwMakeContextCurrent(window);
	glfw::throw_if_error();
}

void glfw_window::swap_buffers()
{
	glfwSwapBuffers(window);
	glfw::throw_if_error();
}

std::pair<int, int> glfw_window::size() const
{
	int w, h;
	glfwGetWindowSize(window, &w, &h);
	glfw::throw_if_error();
	return { w, h };
}

int glfw_window::width() const
{
	return size().first;
}

int glfw_window::height() const
{
	return size().second;
}

void glfw_window::size(int w, int h)
{
	glfwSetWindowSize(window, w, h);
	glfw::throw_if_error();
}

void glfw_window::width(int w)
{
	size(w, height());
}

void glfw_window::height(int h)
{
	size(width(), h);
}

glfw_window::~glfw_window()
{
	glfwDestroyWindow(window);
}
