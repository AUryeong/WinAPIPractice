#include "pch.h"
#include "GameManager.h"
#include "RenderManager.h"

void GameManager::Init(HWND hWnd, HINSTANCE hInstance)
{
	this->hWnd = hWnd;
	this->hInstance = hInstance;
	hdc = GetDC(hWnd);
}

void GameManager::Update()
{
}

void GameManager::Render()
{
	RenderManager::GetInstance()->StartRender();
	RenderManager::GetInstance()->EndRender();
}

void GameManager::Release()
{
	RenderManager::GetInstance()->Release();
	Singleton<GameManager>::Release();
}