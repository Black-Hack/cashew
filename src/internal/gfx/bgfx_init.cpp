#include "bgfx_init.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <bgfx/platform.h>
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#elif BX_PLATFORM_OSX
#define GLFW_EXPOSE_NATIVE_COCOA
#define GLFW_EXPOSE_NATIVE_NSGL
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#else
#error Invalid platform
#endif // BX_PLATFORM_
#include <GLFW/glfw3native.h>

static void* get_glfw_native_window_handle(GLFWwindow* window)
{
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	return (void*)(uintptr_t)glfwGetX11Window(window);
#elif BX_PLATFORM_OSX
	return glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
	return glfwGetWin32Window(window);
#endif // BX_PLATFORM_
}

static void* get_glfw_native_display_type()
{
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	return glfwGetX11Display();
#else // BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	return nullptr;
#endif // BX_PLATFORM_LINUX || BX_PLATFORM_BSD
}

bool init_bgfx(GLFWwindow* window)
{
	bgfx::Init init;

	init.platformData.ndt = get_glfw_native_display_type();
	init.platformData.nwh = get_glfw_native_window_handle(window);

	int width, height;
	glfwGetWindowSize(window, &width, &height);
	init.resolution.width = (uint32_t)width;
	init.resolution.height = (uint32_t)height;
	init.resolution.reset = BGFX_RESET_VSYNC;

	return bgfx::init(init);
}
