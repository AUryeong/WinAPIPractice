#pragma once

#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
private:
	HWND hWnd = nullptr;
	HDC hdc = nullptr;
	HINSTANCE hInstance = nullptr;
public:
	void Init(HWND hWnd, HINSTANCE hInstance);
	
	void Update();
	void Render();

	void Release() override;

	HWND GetHWND() { return hWnd; }
	HDC GetHdc() { return hdc; }
	HINSTANCE GetHInstance() { return hInstance; }
};

