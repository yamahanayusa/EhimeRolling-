#pragma once

//�΂˃J�������g�p�������ꍇ�́ASpringCamera���C���N���[�h����B
#include "camera/SpringCamera.h"

//�N���X�錾
class Player;

class GameCamera:public IGameObject
{
public:

	GameCamera();
	~GameCamera();
	//�X�^�[�g
	bool Start();
	//�A�b�v�f�[�g
	void Update();
	//���W�Ǝ��_���X�V����
	void UpdatePositionAndTarget();
	Player* m_player = nullptr;//�v���C���[
private:
	Vector3 m_toCameraPos = Vector3::One;//�J�����|�X
	SpringCamera  m_springCamera;



};

