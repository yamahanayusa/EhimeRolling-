#pragma once

//ここから下クラス宣言
class Game;

class Player
{
public:
	//プレイや０のステート
	enum EnPlayerState {
		//ここから下にステートを書く
		enPlayerState_Idle,//待機

	};
	Player();
	~Player();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//座標の設定
	void SetPosition(const Vector3 position)
	{
		m_position = position;
	}

	//回転設定
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}
	




	//ここから下プライベート(外部アクセスできないよ)
private:

	//移動処理
	void Move();


	//アニメーション
	enum EnAnimationClip {

		enAnimationClip_Idle,//待機アニメーション
		enAnimationClip_Num,//アニメーション数
	};

	AnimationClip     m_animationClips[enAnimationClip_Num];//アニメーションクリップ
	ModelRender       m_modelRender;                        //モデルレンダー
	Vector3           m_position;                           //座標
	Quaternion        m_rotation;                           //回転処理
	Vector3           m_scale = Vector3::One;               //スケール

	Game* m_game = nullptr;
};

