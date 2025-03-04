#pragma once


//クラス宣言
class Game;


class Player: public IGameObject
{
public:
	//プレイヤーのステート
	enum EnPlayerState {
		//ここから下にステートを書く
		enPlayerState_Idle,//待機


	};
	Player();
	~Player();
	//スタート
	bool Start();
	//アップデート
	void Update();
	//レンダー
	void Render(RenderContext& rc);
	//セットポジション
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}

	//プライベート
private:
	//移動処理
	void Move();

	//ジャンプ処理
	void PlayerJump();

	//アニメーション
	enum EnAnimationClip {



		enAnimationClip_Num,
	};

	// 物理パラメータ
	static constexpr float GRAVITY = 9.8f;   // 重力加速度
	static constexpr float FRICTION = 0.1f;  // 摩擦係数

	AnimationClip  m_animationClip[enAnimationClip_Num];//アニメーションクリップ
	
	Vector3 m_scale =     Vector3::One;//スケール
	CharacterController   m_charaCon;//キャラコン
	Vector3               m_moveSpeed;//スピード
	Game*                 m_game = nullptr;
	Vector3               m_position;//ポジション
};