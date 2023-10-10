#pragma once
#include <memory>
#include <type_traits>

#include "BirdUI/render/pipeline/render_pipe.h"
#include "BirdUI/input/input.h"

#include "BirdUI/components/base_component.h"

template <class T>
class birdui_inst_t
{
public:
	explicit birdui_inst_t()
	{
		input = std::make_unique<bird_input_t>();
	}

	void init(std::shared_ptr<T> render_pipeline);
	void setup_input();

private:
	std::shared_ptr<T> render_pipe = nullptr;
	std::unique_ptr<bird_input_t> input = nullptr;

	std::vector<bird_component_t>
};