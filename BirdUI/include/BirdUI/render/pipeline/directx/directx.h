#pragma once
#include <Windows.h>
#include <cstdint>

class directx_render_t
{
public:
	virtual bool create_device(HWND target_window, uint32_t width, uint32_t height) = 0;
};