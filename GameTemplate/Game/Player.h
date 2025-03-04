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
	//�X�^�[�g
	bool Start();
	//�A�b�v�f�[�g
	void Update();
	//�����_�[
	void Render(RenderContext& rc);
	//�Z�b�g�|�W�V����
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}

	//�v���C�x�[�g
private:
	//�ړ�����
	void Move();

	//�W�����v����
	void PlayerJump();

	//�A�j���[�V����
	enum EnAnimationClip {



		enAnimationClip_Num,
	};

	// �����p�����[�^
	static constexpr float GRAVITY = 9.8f;   // �d�͉����x
	static constexpr float FRICTION = 0.1f;  // ���C�W��

	AnimationClip  m_animationClip[enAnimationClip_Num];//�A�j���[�V�����N���b�v
	
	Vector3 m_scale =     Vector3::One;//�X�P�[��
	CharacterController   m_charaCon;//�L�����R��
	Vector3               m_moveSpeed;//�X�s�[�h
	Game*                 m_game = nullptr;
	Vector3               m_position;//�|�W�V����
};