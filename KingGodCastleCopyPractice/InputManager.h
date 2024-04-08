#pragma once
#include "Singleton.h"

enum class eKeyType
{
	LEFT_MOUSE = VK_LBUTTON,
	RIGHT_MOUSE = VK_RBUTTON,

	UP = VK_UP,
	DOWN = VK_DOWN,
	LEFT = VK_LEFT,
	RIGHT = VK_RIGHT,

	SPACE_BAR = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',

	Q = 'Q',
	E = 'E',
};

enum class KeyState
{
	NONE,
	PRESS,
	DOWN,
	UP,
	END,
};

enum
{
	// KEY_TYPE_COUNT = 256
	KEY_TYPE_COUNT = static_cast<int>(UINT8_MAX) + 1,
	// KEY_STATE_COUNT = 4
	KEY_STATE_COUNT = static_cast<int>(KeyState::END),
};

class InputManager : public Singleton<InputManager>
{
public:
	void Init();
	void Update();

	bool GetButton(eKeyType key) { return GetState(key) == KeyState::PRESS; }
	bool GetButtonDown(eKeyType key) { return GetState(key) == KeyState::DOWN; }
	bool GetButtonUp(eKeyType key) { return GetState(key) == KeyState::UP; }

	POINT GetMousePos() { return mousePos; }

private:
	KeyState GetState(eKeyType key) { return states[static_cast<unsigned long long> (key)]; }

private:
	HWND hWnd = nullptr;

	vector<KeyState> states;

	POINT mousePos = { 0, };
};

