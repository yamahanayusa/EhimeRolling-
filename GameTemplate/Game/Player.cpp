#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include <cmath>

//2025/03/06更新

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Start()
{
	//アニメーションをロードする
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	//モデルレンダーを初期化
	m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num);

	m_modelRender.SetPosition(m_position);

	//キャラクターコントローラーを初期化。
	m_charaCon.Init(
		20.0f,			//半径。
		100.0f,			//高さ。
		m_position		//座標。
	);

	m_modelRender.SetScale(m_scale);

	m_game = FindGO<Game>("game");
	return true;
}

void Player::Update()
{
	//移動処理
	Move();

	//ジャンプ処理
	PlayerJump();
}

void Player::Move()
{
	
}

void Player::PlayerJump()
{
	//もし地面に付いていたら
	if (m_charaCon.IsOnGround())
	{
		//Bボタン推したら
		if (g_pad[0]->IsTrigger(enButtonB))
		{
			//ジャンプする
			m_moveSpeed.y = 120.0f;
		}
	}
	//浮いているとき
	else
	{
		//重力　
		m_moveSpeed.y -= g *deltatime;
	}
}

//描画処理。
void Player::Render(RenderContext& rc)
{
	//ユニティちゃんを描画する。
	m_modelRender.Draw(rc);
}