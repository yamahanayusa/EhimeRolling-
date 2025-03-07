#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "Stage01.h"


bool Game::Start()
{

	g_camera3D->SetPosition({ 0.0f, 100.0f, -600.0f });
	g_camera3D->SetFar(40000.0f);

	//�J�����̃I�u�W�F�N�g���쐬����B
	//m_gameCamera = NewGO<GameCamera>(0, "gamecamera");


	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	//�v���C���[�I�u�W�F�N�g���쐬����
	m_player = NewGO<Player>(0, "player");
	//���W��ݒ肷��
	m_player->SetPosition(m_player->m_position);
	//��]��ݒ肷��
	m_player->SetRotation(m_player->m_rotation);

	//�X�e�[�W�I�u�W�F�N�g���쐬����
	m_stage01 = NewGO<Stage01>(0, "stage01");
	//���W��ݒ肷��
	m_stage01->SetPosition(m_stage01->m_position);
	//��]��ݒ肷��
	m_stage01->SetRotation(m_stage01->m_rotation);

	//�J�����I�u�W�F�N�g���쐬����


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