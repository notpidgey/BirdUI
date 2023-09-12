#include "bird.h"

template <typeof_render_pipe T>
inline birdui_inst_t<T>::birdui_inst_t()
{
	render_pipe.render();
}