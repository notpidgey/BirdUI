#include <memory>
#include <typeinfo>

#include <BirdUI/bird.h>
#include <BirdUI/render/pipeline/directx/dx9.h>
#include <BirdUI/render/pipeline/existing_window.h>

int main()
{
	const std::shared_ptr<existing_window_pipe_t<directx_9_render_t>> window_pipe = 
		std::make_shared<existing_window_pipe_t<directx_9_render_t>>(HWND(0));
	
	std::unique_ptr<birdui_inst_t<existing_window_pipe_t<directx_9_render_t>>> bird = std::make_unique<birdui_inst_t<existing_window_pipe_t<directx_9_render_t>>>();
	bird->init(window_pipe);

	return 1;
}