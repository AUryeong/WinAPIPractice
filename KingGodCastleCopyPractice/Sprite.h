#pragma once

class Sprite 
{
private:
	HDC bitmapDC;
	HBITMAP bitmap;
	BITMAP bitmapInfo;
public:
	Sprite(const WCHAR* fileName);
	~Sprite();

	int alpha;

	const HDC GetBitmapDC() const;
	Vector2 GetSize();
};