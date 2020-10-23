#pragma once

#include <stdexcept>

class glfw_error : public std::exception {
public:
	glfw_error() = default;
	glfw_error(int code, const char* description) noexcept :
		code(code), description(description)
	{}

	const char* what() const final {
		return description;
	}

private:
	int code;
	const char* description;
};
