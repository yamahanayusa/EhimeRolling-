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
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}


private:

};