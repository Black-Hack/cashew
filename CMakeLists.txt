cmake_minimum_required (VERSION 3.12)

project (cashew)

add_executable (${PROJECT_NAME} "cashew.cpp")

# See https://www.glfw.org/docs/3.3/build_guide.html
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(third_party/glfw)

target_link_libraries(${PROJECT_NAME}
	PRIVATE glfw
)
