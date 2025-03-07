#include "stdafx.h"
#include "Player.h"
#include "Game.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Update() 
{
	Move();
}

void Player::Move()
{
	//xzの移動速度を0.0fにする。
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//左スティックの入力量を取得。
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//カメラの前方向と右方向のベクトルを持ってくる。
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	//y方向には移動させない。
	forward.y = 0.0f;
	right.y = 0.0f;

	//左スティックの入力量と500.0fを乗算。
	right *= stickL.x * 500.0f;
	forward *= stickL.y * 500.0f;

	//移動速度にスティックの入力量を加算する。
	moveSpeed += right + forward;

	//地面に付いていたら。
	if (characterController.IsOnGround() == true)
	{
		//重力を無くす。
		moveSpeed.y = 0.0f;
		//Aボタンが押されたら。
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプさせる。
			moveSpeed.y = 240.0f;
		}
	}
	//地面に付いていなかったら。
	else
	{
		//重力を発生させる。
		moveSpeed.y -= 5.5f;
	}

	//キャラクターコントローラーを使って座標を移動させる。
	m_position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//絵描きさんに座標を教える。
	modelRender.SetPosition(m_position);
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