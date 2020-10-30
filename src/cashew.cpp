#include "cashew.hpp"

#include <bgfx/bgfx.h>
#include <bx/math.h>

#include "internal/gfx/glfw.hpp"
#include "internal/gfx/glfw_window.hpp"

#include "internal/gfx/bgfx_init.hpp"

#include <fstream>

struct PosColorVertex
{
	float x, y, z;
	uint32_t abgr;
};

static PosColorVertex cubeVertices[] =
{
	{ -1.0f,  1.0f,  1.0f, 0xff000000 },
	{  1.0f,  1.0f,  1.0f, 0xff0000ff },
	{ -1.0f, -1.0f,  1.0f, 0xff00ff00 },
	{  1.0f, -1.0f,  1.0f, 0xff00ffff },
	{ -1.0f,  1.0f, -1.0f, 0xffff0000 },
	{  1.0f,  1.0f, -1.0f, 0xffff00ff },
	{ -1.0f, -1.0f, -1.0f, 0xffffff00 },
	{  1.0f, -1.0f, -1.0f, 0xffffffff },
};

static const uint16_t cubeTriList[] =
{
	0, 1, 2,
	1, 3, 2,
	4, 6, 5,
	5, 6, 7,
	0, 2, 4,
	4, 2, 6,
	1, 5, 3,
	5, 7, 3,
	0, 4, 1,
	4, 5, 1,
	2, 3, 6,
	6, 3, 7,
};

const bgfx::Memory* load_file(const char* path) {
	std::ifstream f(path, std::ios::binary | std::ios::ate);
	std::streamsize size = f.tellg();
	f.seekg(0, std::ios::beg);

	const bgfx::Memory* mem = bgfx::alloc((uint32_t)size);
	f.read((char*)mem->data, size);

	return mem;
}

int main(int argc, char *argv[])
{
	glfw_window w{1280, 720, "Cashew"};

	if (!init_bgfx(w.expose()))
		return -1;

	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355ff);
	bgfx::setViewRect(0, 0, 0, 1280, 720);

	bgfx::VertexLayout layout;
	layout.begin()
		.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
		.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
		.end();

	bgfx::VertexBufferHandle vbh = bgfx::createVertexBuffer(bgfx::makeRef(cubeVertices, sizeof(cubeVertices)), layout);
	bgfx::IndexBufferHandle ibh = bgfx::createIndexBuffer(bgfx::makeRef(cubeTriList, sizeof(cubeTriList)));

	bgfx::ShaderHandle vsh = bgfx::createShader(load_file(argv[1]));
	bgfx::ShaderHandle fsh = bgfx::createShader(load_file(argv[2]));

	bgfx::ProgramHandle program = bgfx::createProgram(vsh, fsh, true);

	while (!w.close_requested()) {
		glfw::update();

		const bx::Vec3 at = { 0.0f, 0.0f,  0.0f };
		const bx::Vec3 eye = { 0.0f, 0.0f, -5.0f };
		float view[16];
		bx::mtxLookAt(view, eye, at);

		float proj[16];
		bx::mtxProj(proj, 60.0f, 16.f / 9.f, 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);

		bgfx::setViewTransform(0, view, proj);

		bgfx::setVertexBuffer(0, vbh);
		bgfx::setIndexBuffer(ibh);

		bgfx::submit(0, program);

		bgfx::frame();
	}

	bgfx::shutdown();
}
