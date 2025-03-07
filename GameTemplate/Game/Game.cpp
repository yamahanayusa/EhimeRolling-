#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "Stage01.h"


bool Game::Start()
{

	g_camera3D->SetPosition({ 0.0f, 100.0f, -600.0f });
	g_camera3D->SetFar(40000.0f);

	//カメラのオブジェクトを作成する。
	//m_gameCamera = NewGO<GameCamera>(0, "gamecamera");


	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	//プレイヤーオブジェクトを作成する
	m_player = NewGO<Player>(0, "player");
	//座標を設定する
	m_player->SetPosition(m_player->m_position);
	//回転を設定する
	m_player->SetRotation(m_player->m_rotation);

	//ステージオブジェクトを作成する
	m_stage01 = NewGO<Stage01>(0, "stage01");
	//座標を設定する
	m_stage01->SetPosition(m_stage01->m_position);
	//回転を設定する
	m_stage01->SetRotation(m_stage01->m_rotation);

	//カメラオブジェクトを作成する


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