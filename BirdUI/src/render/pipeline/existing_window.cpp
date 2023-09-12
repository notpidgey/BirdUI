#include "render/pipeline/existing_window.h"

void existing_window_pipe_t::create()
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

void existing_window_pipe_t::destroy()
{
}
