#pragma once

class glfw
{
private:
	static glfw singleton;

public:
	static void throw_if_error();

	static void update();

private:
	glfw();
	~glfw();

};
