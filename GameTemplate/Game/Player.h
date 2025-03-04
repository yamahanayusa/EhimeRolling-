#pragma once


//�N���X�錾
class Game;




class Player : public IGameObject
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


		enAnimationClip_Idle,//�ҋ@
		enAnimationClip_Num,//�A�j���[�V������
	};



	AnimationClip  m_animationClips[enAnimationClip_Num];//�A�j���[�V�����N���b�v
	float Playerposition;  // �v���C���[�̈ʒu
	float velocity;  // �v���C���[�̑��x
	ModelRender m_modelRender;//���f�������_�[
	Vector3 m_scale = Vector3::One;//�X�P�[��
	CharacterController   m_charaCon;//�L�����R��
	Vector3               m_moveSpeed;//�X�s�[�h
	Game* m_game = nullptr;
	Vector3               m_position;//�|�W�V����
};