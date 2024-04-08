#include "pch.h"

#include "GameManager.h"
#include "Scene.h"
#include "SceneManager.h"


void SceneManager::Init()
{

}

void SceneManager::Update()
{
	if (nowScene)
	{
		nowScene->Update();
	}
}

void SceneManager::Render()
{
	if (nowScene)
	{
		nowScene->Render();
	}
}

void SceneManager::ChangeScene(eSceneType sceneType)
{
	if (this->sceneType == sceneType) return;

	Scene* newScene = nullptr;

	switch (sceneType)
	{
	}

	SAFE_DELETE(nowScene);

	nowScene = newScene;
	this->sceneType = sceneType;

	newScene->Init();
}