#pragma once
#include <memory>
#include <type_traits>
#include "render/pipeline/render_pipe.h"

template <base_render_pipe rp_t>
class birdui_inst_t
{
public:
	explicit birdui_inst_t()
	{

	}

	void init(std::shared_ptr<rp_t> render_pipeline);

private:
	std::shared_ptr<rp_t> render_pipe = nullptr;
};