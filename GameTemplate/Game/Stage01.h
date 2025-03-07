#pragma once
class Stage01 : public IGameObject
{
public:
	Stage01();
	~Stage01();
	//�X�^�[�g
	bool Start();
	//�A�b�v�f�[�g
	void Update();
	//�����_�[
	void Render(RenderContext& rc);
	/// ���W��ݒ肷��B
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	/// �傫����ݒ肷��B
	void SetScale(const Vector3& scale)
	{
		m_scale = scale;
	}
	/// ��]��ݒ肷��B
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}


	ModelRender					m_modelRender;					//���f�������_�[�B
	Vector3						m_position;						//���W�B
	Vector3						m_scale = Vector3::One;			//�傫���B
	Quaternion					m_rotation;						//��]�B


private:

	//��]����
	void Rotation();

	
	PhysicsStaticObject			m_physicsStaticObject;
	Quaternion                  m_moveRotation;
	


};

