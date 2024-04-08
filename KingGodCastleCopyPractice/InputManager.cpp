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
		// Ű�� ���������� ture
		if (asciiKeys[key] & 0x80)
		{
			KeyState& state = states[key];

			// ���� �����ӿ� Ű�� ���� ���¶��? PRESS
			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Press;
			}
			// �̹����� ���� ��Ȳ�̶��? DOWN
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
