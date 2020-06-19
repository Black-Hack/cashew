#pragma once

#include <stdexcept>
#include <string>

class glfw_error : public std::runtime_error {
public:
	explicit glfw_error(const std::string& what_arg);
	explicit glfw_error(const char* what_arg);
};
