#pragma once
#include "render_pipe.h"
#include <Windows.h>

template <base_dx_render T>
class existing_window_pipe_t : public render_pipe_t<T>
{
public:
	explicit existing_window_pipe_t(HWND hwnd_target)
		: render_pipe_t<T>()
	{
		hwnd = hwnd_target;
	}

	void create() override;
	void destroy() override;

private:
	HWND hwnd;
};

#include "existing_window_t.h"