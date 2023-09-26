#pragma once
#include <functional>
#include <mutex>
#include <Windows.h>

enum class mouse_move_event
{
	control_key = 0x8,
	left_button = 0x1,
	middle_button = 0x10,
	right_button = 0x2,
	shift_key = 0x4,
	xbutton_1 = 0x20,
	xbutton_2 = 0x40
};

class bird_input_t
{
public:
	bird_input_t()
	{
		this_inst = this;
	}

	void set_hooks(
		std::function<void(uint16_t key_index, uint32_t key_state)> key_handler,
		std::function<void(uint16_t, uint16_t)> mouse_move_handler,
		std::function<void(uint16_t)> mouse_click_handler
	);

private:
	std::function<void(uint16_t key_index, uint32_t key_state)> key_event;
	std::function<void(uint16_t, uint16_t)> mouse_move_event;
	std::function<void(uint16_t)> mouse_click_event;

	std::mutex key_mutex;
	uint8_t key_state[256];

	HHOOK keyboard_hook;
	HHOOK mouse_hook;

	inline static bird_input_t* this_inst;
	static LRESULT CALLBACK keyboard_handler(int code, WPARAM wparam, LPARAM lparam);
	static LRESULT CALLBACK mouse_handler(int code, WPARAM wparam, LPARAM lparam);
};