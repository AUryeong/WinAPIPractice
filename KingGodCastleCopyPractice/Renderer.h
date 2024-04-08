#pragma once

class Transform;
class Sprite;
class Renderer
{
public:
	Transform* transform;
	Sprite* sprite;

	void Render();

	virtual Vector2 GetScale();
	virtual Vector2 GetPosition();
};

