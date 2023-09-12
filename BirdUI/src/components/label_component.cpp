#include "components/label_component.h"

void feather_label_component_t::set_text(std::string text)
{
	label_text = text;
}

std::string feather_label_component_t::get_text()
{
	return label_text;
}

void feather_label_component_t::render()
{
	// draw label elements


	// render children components 
	feather_component_t::render();
}
