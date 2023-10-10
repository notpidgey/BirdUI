#pragma once
#include <cstdint>
#include <memory>
#include <vector>

#include "BirdUI/utils/position.h"
#include "BirdUI/utils/dimension.h"

class bird_component_t;

typedef std::weak_ptr<bird_component_t> parent_component_t;
typedef std::vector<std::shared_ptr<bird_component_t>> children_components_t;

#define CREATE_STATIC_CTORS(class_name) \
	template <typename... Args> \
	static std::shared_ptr<class_name> create(Args&&... args) \
	{ \
		return std::make_shared<class_name>(std::forward<Args>(args)...); \
	} 

class bird_component_t : public std::enable_shared_from_this<bird_component_t>
{
public:
	explicit bird_component_t(position_t pos, dimension_t dim, bool render = true, bool input = true)
	{
		position = pos;
		dimension = dimension;

		render_enabled = render;
		input_enabled = input;

		get_true_position();
	}

	virtual void render();
	virtual void handle_input();

	virtual void on_enter() {};
	virtual void on_leave() {};
	virtual void on_hover() {};

	virtual void on_mouse_click() {};
	virtual void on_mouse_down() {};
	virtual void on_mouse_up() {};

	void add_child(std::shared_ptr<bird_component_t> child);
	std::shared_ptr<bird_component_t> get_child(int index);

	void set_parent(std::shared_ptr<bird_component_t> parent);
	std::shared_ptr<bird_component_t> get_parent();

	void set_input(bool input);
	bool get_input();

	void set_render(bool render);
	bool get_render();

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