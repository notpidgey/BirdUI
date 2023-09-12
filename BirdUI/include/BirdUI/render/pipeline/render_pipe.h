#pragma once
#include "render/imgui.h"
#include "render/pipeline/directx/directx.h"

template <typeof_dx_render T>
class render_pipe_t
{
protected:
	void create_device();
	virtual void create() = 0;
	virtual void destroy() = 0;

	T dx_render;
};

template <typename T>
concept typeof_dx_render = std::is_base_of<directx_render_t, T>::value;

template <typename T>
concept typeof_render_pipe = std::is_base_of<render_pipe_t, T>::value;