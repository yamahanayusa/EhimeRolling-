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
	m_modelRender.Init("", m_animationClips, enAnimationClip_Num);

	m_modelRender.SetPosition(m_position);
	m_modelRender.SetScale(m_scale);

	m_game = FindGO<Game>("game");
	return true;
}

void Player::Update()
{
	//移動処理
	Move();
	
	//ジャンプ処理
	PlayerJump()
}

void Player::Move()
{
	// 傾き角度をラジアンに変換
	float angleRad = tiltAngle * M_PI / 180.0f;

	// 加速度 = 重力 * sin(傾き角度)
	float acceleration = GRAVITY * std::sin(angleRad);

	// 摩擦力を計算
	float frictionForce = FRICTION * velocity;

	// 速度を更新
	velocity += (acceleration - frictionForce) * timeStep;

	// 位置を更新
	m_position += velocity * timeStep;

	// 摩擦による停止処理
	if (std::abs(velocity) < 0.01f) {
		velocity = 0.0f;
	}

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
		m_moveSpeed.y -= GRAVITY;
	}
}

