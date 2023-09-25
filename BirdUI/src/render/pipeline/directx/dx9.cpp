#include "render/pipeline/directx/dx9.h"
#include "render/imgui_impl_dx9.h"

#include <d3dx9.h>

bool directx_9_render_t::create_device(HWND target_window, uint32_t width, uint32_t height)
{
	d3d_instance = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3d_params = { 0 };
	d3d_params.Windowed = TRUE;
	d3d_params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3d_params.hDeviceWindow = target_window;
	d3d_params.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3d_params.BackBufferWidth = width;
	d3d_params.BackBufferHeight = height;
	d3d_params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	d3d_params.EnableAutoDepthStencil = TRUE;
	d3d_params.AutoDepthStencilFormat = D3DFMT_D16;

	HRESULT ret = d3d_instance->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, target_window, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3d_params, &d3d_device);
	if (FAILED(ret))
		return false;

	return true;
}

bool directx_9_render_t::init_imgui()
{
	return ImGui_ImplDX9_Init(d3d_device);
}
