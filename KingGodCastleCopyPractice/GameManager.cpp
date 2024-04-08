#include "pch.h"

#include "GameManager.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "InputManager.h"

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
	SceneManager::GetInstance()->Render();
	RenderManager::GetInstance()->EndRender();
}

void GameManager::Release()
{
	InputManager::GetInstance()->Release();
	SceneManager::GetInstance()->Release();
	RenderManager::GetInstance()->Release();
	TimeManager::GetInstance()->Release();
	Singleton<GameManager>::Release();
}