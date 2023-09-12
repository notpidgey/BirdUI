#include "render/pipeline/render_pipe.h"
#include <d3dx9.h>
#include <d3d10.h>
#include <d3d11.h>
#include <d3d12.h>

void render_pipe_t::create_device()
{
	switch (render)
	{
	case render_type::render_dx9:
		break;
	case render_type::render_dx11:
		break;
	case render_type::render_dx12:
		break;
	default:
		break;
	}
}
