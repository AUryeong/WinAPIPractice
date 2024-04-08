#include "pch.h"

#include "Transform.h"

Transform::Transform(Vector2 pos, Vector2 scale)
{
	this->position = pos;
	this->scale = scale;
}

void Transform::SetPosition(Vector2 position)
{
	this->position.x = position.x;
	this->position.y = position.y;
}

void Transform::SetScale(Vector2 scale)
{
	this->scale.x = scale.x;
	this->scale.y = scale.y;
}

const Vector2 Transform::GetPosition() const
{
	return position;
}

const Vector2 Transform::GetScale() const
{
	return scale;
}
