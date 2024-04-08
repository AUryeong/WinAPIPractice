#include "pch.h"

#include "Sprite.h"
#include "Transform.h"

#include "Renderer.h"
#include "RenderManager.h"

void Renderer::Render()
{
	RenderManager::GetInstance()->Render(this);
}

Vector2 Renderer::GetScale()
{	
	return sprite->GetSize() * transform->scale;
}

Vector2 Renderer::GetPosition()
{
	return transform->GetPosition();
}
