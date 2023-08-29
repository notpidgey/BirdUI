#pragma once
#include <string>

#include "base_component.h"

class feather_label_component_t : public feather_component_t
{
public:
	feather_label_component_t(position_t pos, dimension_t dim, const std::string& label)
		: feather_component_t(pos, dim, true, false)
	{
		label_text = label;
	}

	void set_text(std::string text);
	std::string get_text();

private:
	std::string label_text;

	void render() override;
};