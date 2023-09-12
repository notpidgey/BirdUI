#pragma once
#include "directx.h"

class IDirect3D9;
class IDirect3DDevice9;
class directx_9_render_t : public directx_render_t
{
public:
	bool create_device(HWND target_window, uint32_t width, uint32_t height);

private:
	IDirect3D9* d3d_instance;
	IDirect3DDevice9* d3d_device;
};