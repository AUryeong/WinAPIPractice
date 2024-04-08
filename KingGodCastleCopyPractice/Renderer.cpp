#include "pch.h"

#include "Sprite.h"
#include "Transform.h"
#include "Renderer.h"

void Renderer::Render()
{
}

Vector2 Renderer::GetScale()
{
	return sprite->GetSize() * transform->scale;
}

Vector2 Renderer::GetPosition()
{
	return transform->GetPosition();
}
