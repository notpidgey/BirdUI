#pragma once
#include <cstdint>
#include <memory>
#include <vector>

#include "utils/position.h"
#include "utils/dimension.h"

class feather_component_t;

typedef std::weak_ptr<feather_component_t> parent_component_t;
typedef std::vector<std::shared_ptr<feather_component_t>> children_components_t;

class feather_component_t : public std::enable_shared_from_this<feather_component_t>
{
public:
	virtual void render();
	virtual void handle_input();

	virtual void on_enter() {};
	virtual void on_leave() {};
	virtual void on_hover() {};

	virtual void on_mouse_click() {};
	virtual void on_mouse_down() {};
	virtual void on_mouse_up() {};

	void add_child(std::shared_ptr<feather_component_t> child);
	std::shared_ptr<feather_component_t> get_child(int index);

	void set_parent(std::shared_ptr<feather_component_t> parent);
	std::shared_ptr<feather_component_t> get_parent();

	position_t get_position();
	position_t get_true_position();
	position_t get_true_position_cache();
	
	void invalidate_true_position_cache();

	dimension_t get_dimension();

protected:
	children_components_t children_components;

	position_t position;
	position_t true_position;

	dimension_t dimension;

	bool true_position_reset;

	bool render_enabled;
	bool input_enabled;

private:
	parent_component_t parent_component;
};