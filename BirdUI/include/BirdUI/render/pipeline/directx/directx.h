#pragma once
#include <type_traits>
#include <cstdint>

#include <Windows.h>

class directx_render_t
{
public:
	virtual bool create_device(HWND target_window, uint32_t width, uint32_t height) = 0;
};

template <typename T>
concept base_dx_render = std::is_base_of<directx_render_t, T>::value;