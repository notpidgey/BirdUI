#pragma once
#include <type_traits>
#include "BirdUI/render/imgui.h"
#include "BirdUI/render/pipeline/directx/directx.h"

template <base_dx_render T>
class render_pipe_t
{
protected:
	void create_device();
	virtual void create() = 0;
	virtual void destroy() = 0;

	T dx_render;
};