#include "pch.h"

#include "GameManager.h"
#include "InputManager.h"


void InputManager::Init()
{
	hWnd = GameManager::GetInstance()->GetHWND();
	states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	HWND foucsHWnd = GetFocus();
	if (foucsHWnd != hWnd) return;

	BYTE asciiKeys[KEY_TYPE_COUNT] = {};

	if (::GetKeyboardState(asciiKeys) == false)
	{
		return;
	}

	for (unsigned int key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// 키가 눌려있으면 ture
		if (asciiKeys[key] & 0x80)
		{
			KeyState& state = states[key];

			// 이전 프레임에 키를 누른 상태라면? PRESS
			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Press;
			}
			// 이번에만 눌린 상황이라면? DOWN
			else
			{
				state = KeyState::Down;
			}
		}
		else
		{
			KeyState& state = states[key];

			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Up;
			}
			else
			{
				state = KeyState::None;
			}
		}
	}

	::GetCursorPos(&mousePos);
	::ScreenToClient(hWnd, &mousePos);
}
