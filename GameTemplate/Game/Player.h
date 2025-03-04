#pragma once


//クラス宣言
class Game;




class Player : public IGameObject
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


		enAnimationClip_Idle,//待機
		enAnimationClip_Num,//アニメーション数
	};



	AnimationClip  m_animationClips[enAnimationClip_Num];//アニメーションクリップ
	float Playerposition;  // プレイヤーの位置
	float velocity;  // プレイヤーの速度
	ModelRender m_modelRender;//モデルレンダー
	Vector3 m_scale = Vector3::One;//スケール
	CharacterController   m_charaCon;//キャラコン
	Vector3               m_moveSpeed;//スピード
	Game* m_game = nullptr;
	Vector3               m_position;//ポジション
};