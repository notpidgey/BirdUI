#pragma once
#include "render_pipe.h"

#include <Windows.h>
#include <tuple>

template <base_dx_render T>
class existing_window_pipe_t : public render_pipe_t<T>
{
public:
	explicit existing_window_pipe_t(HWND hwnd_target)
	{
		hwnd = hwnd_target;
	}

	bool run_frame() override;

	bool create() override;
	bool destroy() override;

private:
	HWND hwnd;

	std::pair<uint32_t, uint32_t> get_window_rect();
};

#include "existing_window_t.h"