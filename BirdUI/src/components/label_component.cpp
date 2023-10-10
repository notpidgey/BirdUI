#include "components/label_component.h"

void bird_label_component_t::set_text(std::string text)
{
	label_text = text;
}

std::string bird_label_component_t::get_text()
{
	return label_text;
}

void bird_label_component_t::render()
{
	// draw label elements


	// render children components 
	bird_component_t::render();
}
