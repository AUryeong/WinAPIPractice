#pragma once
#include "Singleton.h"

class Scene;
class SceneManager : public Singleton<SceneManager>
{
public:
	void Init();
	void Update();
	void Render();
	void Release() override;

public:
	void ChangeScene(eSceneType sceneType);

private:
	Scene* nowScene = nullptr;
	eSceneType sceneType = eSceneType::NONE;
};