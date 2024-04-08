#pragma once

class Sprite
{
private:
	HDC bitmapDC = nullptr;
	HBITMAP bitmap = nullptr;
	HBITMAP renderBitmap = nullptr;
	BITMAP bitmapInfo = { 0, };

public:
	Sprite(const WCHAR* fileName);
	~Sprite();

	int alpha;

	const HDC GetBitmapDC() const;
	Vector2 GetSize();
};