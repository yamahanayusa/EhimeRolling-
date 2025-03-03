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
	//アニメーションをロードする


	//モデルレンダーを初期化
	m_modelRender.Init("",m_animationClips,enAnimationClip_Num);
	//ポジション
	m_modelRender.SetPosition(m_position);
	//スケール
	m_modelRender.SetScale(m_scale);
	//初期位置
	m_position = { 0.0f,0.0f,0.0f };


	m_game = FindGO<Game>("game");
	return true;
}