#include "glfw_error.hpp"

glfw_error::glfw_error(const std::string& what_arg) :
	std::runtime_error(what_arg)
{}

glfw_error::glfw_error(const char* what_arg) :
	std::runtime_error(what_arg)
{}
