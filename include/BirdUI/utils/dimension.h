#pragma once
#include <cstdint>

struct dimension_t
{
	dimension_t(uint32_t pos_width, uint32_t pos_height)
	{
		width = pos_width;
		height = pos_height;
	}

	dimension_t()
	{
		width = 0;
		height = 0;
	}

	uint32_t width;
	uint32_t height;
};