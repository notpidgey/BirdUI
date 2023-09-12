#pragma once
#include "render/imgui.h"

enum class render_type
{
	render_dx9,
	render_dx11,
	render_dx12
};

class render_pipe_t
{
public:
	virtual void create() = 0;
	virtual void destroy() = 0;

protected:
	explicit render_pipe_t(render_type ren)
	{
		render = ren;
	}

	render_type render;
};