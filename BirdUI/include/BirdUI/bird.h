#pragma once
#include <type_traits>
#include "render/pipeline/render_pipe.h"

template <typename T>
concept typeof_render_pipe = std::is_base_of<render_pipe_t, T>::value;

template <typeof_render_pipe T>
class birdui_inst_t
{
public:
	birdui_inst_t();

private:
	T render_pipe;
};