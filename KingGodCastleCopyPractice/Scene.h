#pragma once

enum class eSceneType
{
	NONE,
	GAME_SCENE,
	MAX
};

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init();
	virtual void Update();
	virtual void Render();

};