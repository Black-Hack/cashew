#pragma once

#include <utility>

struct GLFWwindow;

class glfw_window
{
private:
	GLFWwindow* window;

public:
	glfw_window(int width, int height, const char* title);

	bool close_requested() const;

	std::pair<int, int> size() const;
	int width() const;
	int height() const;

	void size(int w, int h);
	void width(int w);
	void height(int h);

	~glfw_window();
};
