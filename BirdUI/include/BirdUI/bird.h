#pragma once
#include <memory>
#include <type_traits>
#include "render/pipeline/render_pipe.h"

template <class T>
class birdui_inst_t
{
public:
	explicit birdui_inst_t()
	{

	}

	void init(std::shared_ptr<T> render_pipeline);

private:
	std::shared_ptr<T> render_pipe = nullptr;
};