#pragma once
#include "render_pipe.h"
#include <Windows.h>

class existing_window_pipe_t : public render_pipe_t
{
public:
	explicit existing_window_pipe_t(render_type ren)
		: render_pipe_t(ren)
	{

	}

	void create();
	void destroy();
};