cmake_minimum_required (VERSION 3.12)

project (cashew CXX)

# CONFIGURE_DEPENDS uses CMake 3.12
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} CONFIGURE_DEPENDS "src/*.cpp")

add_executable (${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
)

# See https://www.glfw.org/docs/3.3/build_guide.html
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(third_party/glfw)

add_subdirectory(third_party/glm)

set(BGFX_BUILD_TOOLS ON CACHE BOOL "Build bgfx tools." FORCE)
set(BGFX_BUILD_EXAMPLES OFF CACHE BOOL "Build bgfx examples." FORCE)
set(BGFX_INSTALL OFF CACHE BOOL "Create installation target." FORCE)
set(BGFX_INSTALL_EXAMPLES OFF CACHE BOOL "Install examples and their runtimes." FORCE)
set(BGFX_CUSTOM_TARGETS OFF CACHE BOOL "Include convenience custom targets." FORCE)
set(BGFX_USE_OVR OFF CACHE BOOL "Build with OVR support." FORCE)
set(BGFX_AMALGAMATED OFF CACHE BOOL "Amalgamated bgfx build for faster compilation" FORCE)
set(BX_AMALGAMATED OFF CACHE BOOL "Amalgamated bx build for faster compilation" FORCE)
set(BGFX_CONFIG_DEBUG OFF CACHE BOOL "Enables debug configuration on all builds" FORCE)
set(BGFX_CONFIG_RENDERER_WEBGPU OFF CACHE BOOL "Enables the webgpu renderer" FORCE)
add_subdirectory(third_party/bgfx)

target_link_libraries(${PROJECT_NAME}
	PRIVATE glfw
	PRIVATE glm
	PRIVATE bgfx
)
