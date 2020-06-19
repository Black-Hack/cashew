cmake_minimum_required (VERSION 3.12)

project (cashew)

# CONFIGURE_DEPENDS uses CMake 3.12
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} CONFIGURE_DEPENDS "src/*.cpp")

add_executable (${PROJECT_NAME} ${SOURCES})

# See https://www.glfw.org/docs/3.3/build_guide.html
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(third_party/glfw)

target_link_libraries(${PROJECT_NAME}
	PRIVATE glfw
)
