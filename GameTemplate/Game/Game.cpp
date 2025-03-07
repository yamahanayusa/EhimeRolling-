#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Stage01.h"
#include "GameCamera.h"

Game::Game()
{
	m_player = NewGO<Player>(0, "player");
	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");
	m_stage01 = NewGO<Stage01>(0, "stage01");


}

Game::~Game()

{

}



bool Game::Start()
{
	//m_modelRender.Init("Assets/modelData/unityChan.tkm");
	
	return true;
}

void Game::Update()
{
	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}