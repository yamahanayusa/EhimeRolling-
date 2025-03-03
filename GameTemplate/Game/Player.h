#pragma once

//�������牺�N���X�錾
class Game;

class Player
{
public:
	//�v���C��O�̃X�e�[�g
	enum EnPlayerState {
		//�������牺�ɃX�e�[�g������
		enPlayerState_Idle,//�ҋ@

	};
	Player();
	~Player();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//���W�̐ݒ�
	void SetPosition(const Vector3 position)
	{
		m_position = position;
	}

	//��]�ݒ�
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}
	




	//�������牺�v���C�x�[�g(�O���A�N�Z�X�ł��Ȃ���)
private:

	//�ړ�����
	void Move();


	//�A�j���[�V����
	enum EnAnimationClip {

		enAnimationClip_Idle,//�ҋ@�A�j���[�V����
		enAnimationClip_Num,//�A�j���[�V������
	};

	AnimationClip     m_animationClips[enAnimationClip_Num];//�A�j���[�V�����N���b�v
	ModelRender       m_modelRender;                        //���f�������_�[
	Vector3           m_position;                           //���W
	Quaternion        m_rotation;                           //��]����
	Vector3           m_scale = Vector3::One;               //�X�P�[��

	Game* m_game = nullptr;
};

