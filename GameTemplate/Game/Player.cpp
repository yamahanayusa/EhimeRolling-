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
	m_modelRender.Init("",m_animationClips,enAnimationClip_Num);
	//�|�W�V����
	m_modelRender.SetPosition(m_position);
	//�X�P�[��
	m_modelRender.SetScale(m_scale);
	//�����ʒu
	m_position = { 0.0f,0.0f,0.0f };


	m_game = FindGO<Game>("game");
	return true;
}