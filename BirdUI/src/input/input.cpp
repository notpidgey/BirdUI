#include "BirdUI/input/input.h"
#include <Windows.h>

void bird_input_t::set_hooks(
	std::function<void(uint16_t key_index, uint32_t key_state)> key_handler,
	std::function<void(uint16_t, uint16_t)> mouse_move_handler,
	std::function<void(uint16_t)> mouse_click_handler
)
{
	key_event = key_handler;
	mouse_move_event = mouse_move_handler;
	mouse_click_event = mouse_click_handler;

	GetKeyboardState(key_state);
	keyboard_hook = SetWindowsHookExA(WH_KEYBOARD_LL, &bird_input_t::keyboard_handler, 0, 0);
	mouse_hook = SetWindowsHookExA(WH_MOUSE_LL, &bird_input_t::mouse_handler, 0, 0);
}

LRESULT bird_input_t::keyboard_handler(int code, WPARAM wparam, LPARAM lparam)
{
	KBDLLHOOKSTRUCT* keyboard_structure = (KBDLLHOOKSTRUCT*)lparam;
	if (wparam == WM_KEYDOWN || wparam == WM_KEYUP) 
	{
		DWORD key_code = keyboard_structure->vkCode;
		DWORD flags = keyboard_structure->flags;

		// ignore mouse clicks as key input
		bird_input_t* inst = this_inst;
		{
			inst->key_mutex.lock();
			inst->key_state[keyboard_structure->vkCode] = keyboard_structure->flags;
			inst->key_mutex.unlock();
		}
	}

	return CallNextHookEx(this_inst->keyboard_hook, code, wparam, lparam);
}

LRESULT bird_input_t::mouse_handler(int code, WPARAM wparam, LPARAM lparam)
{
	MSLLHOOKSTRUCT* mouse_info = (MSLLHOOKSTRUCT*)lparam;
	if (wparam == WM_MOUSEMOVE)
	{
		bird_input_t* inst = this_inst;
		{
			LPARAM mouse_position = lparam;
			uint16_t x = LOWORD(mouse_position);
			uint16_t y = HIWORD(mouse_position);

			inst->mouse_move_event(x, y);
		}
	}

	return CallNextHookEx(this_inst->mouse_hook, code, wparam, lparam);
}
