#include "pch.h"
#include "GameManager.h"
#include "Sprite.h"

Sprite::Sprite(const WCHAR* fileName) : alpha(255)
{
	bitmap = static_cast<HBITMAP>(LoadImage(nullptr, fileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	GetObject(bitmap, sizeof(BITMAP), &bitmapInfo);

	HDC hdc = GameManager::GetInstance()->GetHdc();
	bitmapDC = CreateCompatibleDC(hdc);
	SelectObject(bitmapDC, bitmap);
}

Sprite::~Sprite()
{
	DeleteDC(bitmapDC);
}

const HDC Sprite::GetBitmapDC() const
{
	return bitmapDC;
}

Vector2 Sprite::GetSize()
{
	return Vector2(bitmapInfo.bmWidth, bitmapInfo.bmHeight);
}
