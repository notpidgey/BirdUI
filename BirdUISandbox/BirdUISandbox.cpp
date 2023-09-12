#include <memory>
#include <typeinfo>

#include <BirdUI/bird.h>
#include <BirdUI/render/pipeline/directx/dx9.h>
#include <BirdUI/render/pipeline/existing_window.h>

int main()
{
	std::shared_ptr<existing_window_pipe_t<directx_9_render_t>> window_pipe = std::make_shared<existing_window_pipe_t<directx_9_render_t>>();
	std::unique_ptr<birdui_inst_t<typeof(window_pipe)>> bird = std::make_unique<typeof(window_pipe)>();
	bird->init(window_pipe);

	return 1;
}