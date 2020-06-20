#include "cashew.hpp"

#include <GL/glew.h>

#include "internal/gfx/glfw.hpp"
#include "internal/gfx/glfw_window.hpp"

int main()
{
	glfw_window w{1280, 720, "Cashew"};
	w.make_context_current();

	if (glewInit() != GLEW_OK)
		return -1;

	while (!w.close_requested()) {
		glClear(GL_COLOR_BUFFER_BIT);
		w.swap_buffers();
		glfw::update();
	}
}
