#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include <cmath>

//2025/03/04

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Start()
{
	//�A�j���[�V���������[�h����
	

	//���f�������_�[��������
	m_modelRender.Init("", m_animationClips, enAnimationClip_Num);

	m_modelRender.SetPosition(m_position);
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
		m_moveSpeed.y -= 10;
	}
}

