#include "stdafx.h"
#include "Stage01.h"

Stage01::Stage01()
{

}

Stage01::~Stage01()
{

}

bool Stage01::Start()
{
	//���f����ǂݍ��ށB
	m_modelRender.Init("Assets/Stage01/stage.tkm");
	//���W��ݒ肷��
	m_modelRender.SetPosition(m_position);
	//�傫����ݒ肷��
	m_modelRender.SetScale(m_scale);
	//��]��ݒ肷��
	m_modelRender.SetRotation(m_rotation);
	//���f�����X�V����
	m_modelRender.Update();
	//�����蔻����쐬����B
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	return true;

}


void Stage01::Update()
{
	//��]����
	Rotation();

	//���f���̍X�V�����B
	m_modelRender.Update();
}

void Stage01::Rotation()
{
	m_moveRotation.a = 0.0f;//X���@
	m_moveRotation.b = 0.0f;//Y��
	m_moveRotation.g = 0.0f;//Z��

	//���X�e�B�b�N�̓��͗ʂ��󂯎��
	float lStick_x = g_pad[0]->GetLStickXF();
	float lStick_y = g_pad[0]->GetLStickYF();





}

void Stage01::Render(RenderContext& rc)
{
	//���f����`�悷��
	m_modelRender.Draw(rc);
}