#include "BirdUI/components/container_component.h"
#include "BirdUI/utils/limit.h"

void container_component_t::add_child(std::shared_ptr<bird_component_t> child)
{
	child->set_parent(shared_from_this());
	component_container.push_back(child);
}

void container_component_t::render()
{
	for (auto& child : children_components)
	{
		if (child->get_render())
		{
			// setup render boundaries to prevent component from drawing outside of them
			auto [x, y] = child->get_true_position_cache();
			auto [width, height] = child->get_dimension();

			render_limit_t render_limit = {
				x, y,
				x + width, y + height
			};

			g_render.pDevice->SetScissorRect(&render_limit);
		}
	}
}
