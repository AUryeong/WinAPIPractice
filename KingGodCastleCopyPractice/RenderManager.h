#pragma once
#include "Singleton.h"

class Renderer;
class RenderManager : public Singleton<RenderManager>
{
private:
	HWND hWnd = nullptr;
	HDC hdc = nullptr;

	HDC hdcBack = nullptr;
	HBITMAP bitmapBack = nullptr;

	RECT clientRect = { 0, };
public:
	void Init();
	void StartRender();
	void Render(Renderer* renderer);
	void EndRender();

	void Release() override;
};

