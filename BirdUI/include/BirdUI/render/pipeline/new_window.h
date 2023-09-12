#pragma once
#include "render_pipe.h"
#include <Windows.h>

template <typeof_dx_render T>
class new_window_pipe_t : public render_pipe_t<T>
{
public:
	explicit new_window_pipe_t(uint32_t window_width, uint32_t window_height, bool default_controls)
		: render_pipe_t()
	{
		width = window_width;
		height = window_height;
		controls = default_controls;
	}

	void create();
	void destroy();

private:
	uint32_t width;
	uint32_t height;
	bool controls;
};