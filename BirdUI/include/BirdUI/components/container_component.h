#pragma once
#include "base_component.h"

class container_component_t : public bird_component_t
{
public:
	container_component_t(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		: bird_component_t(position_t{ x, y }, dimension_t{ width, height }, true, true)
	{

	}

	void add_child(std::shared_ptr<bird_component_t> child);

private:
	std::vector<std::shared_ptr<bird_component_t>> component_container;

	void render() override;
};