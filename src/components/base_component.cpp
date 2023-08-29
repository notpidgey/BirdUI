#include "components/base_component.h"

void feather_component_t::render()
{
	for (auto& child : children_components)
	{
		if(child->render_enabled)
			child->render();
	}
}

void feather_component_t::handle_input()
{
	for (auto& child : children_components)
	{
		if (child->input_enabled)
			child->handle_input();
	}
}

void feather_component_t::add_child(std::shared_ptr<feather_component_t> add_child)
{
	children_components.push_back(add_child);
}

std::shared_ptr<feather_component_t> feather_component_t::get_child(int index)
{
	return children_components[index];
}

void feather_component_t::set_parent(std::shared_ptr<feather_component_t> parent)
{
	parent_component = parent;
}

std::shared_ptr<feather_component_t> feather_component_t::get_parent()
{
	return parent_component.lock();
}

position_t feather_component_t::get_position()
{
	return { position.x, position.y };
}

position_t feather_component_t::get_true_position()
{
	uint32_t final_x = 0, final_y = 0;

	std::shared_ptr<feather_component_t> current_parent = this->get_parent();
	while (current_parent)
	{
		auto [parent_x, parent_y] = current_parent->get_position();
		final_x += parent_x;
		final_y += parent_y;

		current_parent = current_parent->get_parent();
	}

	return { final_x, final_y };
}

position_t feather_component_t::get_true_position_cache()
{
	if (true_position_reset)
	{
		true_position = get_true_position();
		true_position_reset = false;
	}

	return true_position;
}

void feather_component_t::invalidate_true_position_cache()
{
	for (auto& child : children_components)
	{
		child->invalidate_true_position_cache();
	}
	
	true_position_reset = true;
}

dimension_t feather_component_t::get_dimension()
{
	return dimension;
}
