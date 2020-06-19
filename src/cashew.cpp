#include "cashew.hpp"

#include "internal/gfx/glfw.hpp"
#include "internal/gfx/glfw_window.hpp"

int main()
{
	glfw_window w{1280, 720, "Cashew"};
	while (!w.close_requested()) glfw::update();
}
