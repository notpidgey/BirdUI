#pragma once
#include <cstdint>

struct position_t
{
	position_t(uint32_t pos_x, uint32_t pos_y)
	{
		x = pos_x;
		y = pos_y;
	}

	position_t()
	{
		x = 0;
		y = 0;
	}

	uint32_t x;
	uint32_t y;
};