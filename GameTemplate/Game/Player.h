#pragma once


//�N���X�錾
class Game;


class Player: public IGameObject
{
public:
	//�v���C���[�̃X�e�[�g
	enum EnPlayerState {
		//�������牺�ɃX�e�[�g������
		enPlayerState_Idle,//�ҋ@


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