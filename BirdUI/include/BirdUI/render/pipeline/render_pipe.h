#pragma once
#include "BirdUI/render/imgui.h"
#include "BirdUI/render/pipeline/directx/directx.h"

template <base_dx_render T>
class render_pipe_t
{
public:
	virtual void run_frame() = 0;

protected:
	virtual bool create() = 0;
	virtual bool destroy() = 0;

	T dx_render;
};