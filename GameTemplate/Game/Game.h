#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class Stage01;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	Player* m_player;
	GameCamera* m_gameCamera;
	Stage01* m_stage01;
	ModelRender m_modelRender;
	Vector3 m_pos;
};

