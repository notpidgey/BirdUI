#include "bird.h"

template <class T>
void birdui_inst_t<T>::init(std::shared_ptr<T> render_pipeline)
{
    // Implementation of the init function
    // You can use the render_pipeline shared pointer here
}

template<class T>
void birdui_inst_t<T>::setup_components()
{
    components = std::make_unique<container_component_t>(0, 0)
}

template<class T>
void birdui_inst_t<T>::setup_input()
{
    input = std::make_unique<bird_input_t>();
}
