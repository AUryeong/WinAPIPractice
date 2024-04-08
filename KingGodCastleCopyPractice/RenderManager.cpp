#include "pch.h"

#include "Renderer.h"
#include "Sprite.h"
#include "GameManager.h"
#include "RenderManager.h"

void RenderManager::Init()
{
	hWnd = GameManager::GetInstance()->GetHWND();
	hdc = GameManager::GetInstance()->GetHdc();

	GetClientRect(hWnd, &clientRect);
	hdcBack = CreateCompatibleDC(hdc);
	HBITMAP clientBitmap = CreateCompatibleBitmap(hdcBack, clientRect.right - clientRect.left, clientRect.bottom - clientRect.top);
	bitmapBack = static_cast<HBITMAP>(SelectObject(hdcBack, bitmapBack));

	SelectObject(hdcBack, static_cast<HBRUSH>(GetStockObject(DC_BRUSH)));
	SetDCBrushColor(hdcBack, RGB(0, 0, 0));
}

void RenderManager::StartRender()
{
	FillRect(hdcBack, &clientRect, static_cast<HBRUSH>(GetStockObject(DC_BRUSH)));
}

void RenderManager::Render(Renderer* renderer)
{
	auto position = renderer->GetPosition();
	auto scale = renderer->GetScale();

	auto textureSize = renderer->sprite->GetSize();

	BLENDFUNCTION bf = { 0, };
	bf.BlendOp = AC_SRC_OVER;
	bf.AlphaFormat = AC_SRC_ALPHA;
	bf.SourceConstantAlpha = renderer->sprite->alpha;

	AlphaBlend(hdcBack, position.x, position.y, scale.x, scale.y,
		renderer->sprite->GetBitmapDC(), 0, 0,
		textureSize.x, textureSize.y, bf);
}

void RenderManager::EndRender()
{
	BitBlt(hdc, 0, 0, clientRect.right, clientRect.bottom, hdcBack, 0, 0, SRCCOPY);
}

void RenderManager::Release()
{
	DeleteObject(SelectObject(hdcBack, bitmapBack));
	DeleteDC(hdcBack);
	Singleton<RenderManager>::Release();
}
