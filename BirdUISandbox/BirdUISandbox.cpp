#include <memory>

#include <BirdUI/bird.h>
#include <BirdUI/render/pipeline/existing_window.h>

int main()
{
	std::shared_ptr<existing_window_pipe_t> window_pipe = std::make_shared<existing_window_pipe_t>(render_type::render_dx9, );
	
	std::unique_ptr<birdui_inst_t<existing_window_pipe_t>> bird = std::make_unique<birdui_inst_t<existing_window_pipe_t>>();
	bird->init(window_pipe);

	return 1;
}