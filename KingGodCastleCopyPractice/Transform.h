#pragma once
class Transform
{
public:
	Vector2 position;
	Vector2 scale;
public:
	Transform(Vector2 pos, Vector2 scale);

	void SetPosition(Vector2 pos);
	void SetScale(Vector2 size);

	const Vector2 GetPosition() const;
	const Vector2 GetScale() const;
};