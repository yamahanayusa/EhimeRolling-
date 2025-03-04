#include "stdafx.h"
#include "Player.h"
#include "Game.h"

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
	PlayerJump()
}

void Player::Move()
{
	// �X���p�x�����W�A���ɕϊ�
	float angleRad = tiltAngle * M_PI / 180.0f;

	// �����x = �d�� * sin(�X���p�x)
	float acceleration = GRAVITY * std::sin(angleRad);

	// ���C�͂��v�Z
	float frictionForce = FRICTION * velocity;

	// ���x���X�V
	velocity += (acceleration - frictionForce) * timeStep;

	// �ʒu���X�V
	m_position += velocity * timeStep;

	// ���C�ɂ���~����
	if (std::abs(velocity) < 0.01f) {
		velocity = 0.0f;
	}

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
		m_moveSpeed.y -= GRAVITY;
	}
}

