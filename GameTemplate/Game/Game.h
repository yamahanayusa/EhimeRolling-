#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class Stage01;

class Game : public IGameObject
{
public:
	Game() {}
	~Game() {}
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	ModelRender m_modelRender;
	Vector3 m_pos;
	Player* m_player = nullptr;
	GameCamera* m_gameCamera = nullptr;
	Stage01* m_stage01 = nullptr;

};