#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include <cmath>

//2025/03/06�X�V

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Start()
{
	//�A�j���[�V���������[�h����
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	//���f�������_�[��������
	m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num);

	m_modelRender.SetPosition(m_position);

	//�L�����N�^�[�R���g���[���[���������B
	m_charaCon.Init(
		20.0f,			//���a�B
		100.0f,			//�����B
		m_position		//���W�B
	);

	m_modelRender.SetScale(m_scale);

	m_game = FindGO<Game>("game");
	return true;
}

void Player::Update()
{
	//�ړ�����
	Move();

	//�W�����v����
	PlayerJump();
}

void Player::Move()
{
	
}

void Player::PlayerJump()
{
	//�����n�ʂɕt���Ă�����
	if (m_charaCon.IsOnGround())
	{
		//B�{�^����������
		if (g_pad[0]->IsTrigger(enButtonB))
		{
			//�W�����v����
			m_moveSpeed.y = 120.0f;
		}
	}
	//�����Ă���Ƃ�
	else
	{
		//�d�́@
		m_moveSpeed.y -= g *deltatime;
	}
}

//�`�揈���B
void Player::Render(RenderContext& rc)
{
	//���j�e�B������`�悷��B
	m_modelRender.Draw(rc);
}