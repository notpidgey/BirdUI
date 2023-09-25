#pragma once
#include "existing_window.h"
#include "BirdUI/render/imgui_impl_win32.h"

template<base_dx_render T>
bool existing_window_pipe_t<T>::run_frame()
{

	while (true)
	{

	}
	
	return false;
}

template <base_dx_render T>
bool existing_window_pipe_t<T>::create()
{
	auto [width, height] = get_window_rect();
	this->dx_render.create_device(hwnd, width, height);

	ImGui::CreateContext();
	ImGui_ImplWin32_Init((HWND)hwnd);
	
	return this->dx_render.init_imgui();
}

template <base_dx_render T>
bool existing_window_pipe_t<T>::destroy()
{
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	return true;
}

template<base_dx_render T>
std::pair<uint32_t, uint32_t> existing_window_pipe_t<T>::get_window_rect()
{
	RECT rectangle;
	GetWindowRect(hwnd, &rectangle);

	return { rectangle.right - rectangle.left, rectangle.bottom - rectangle.top };
}
