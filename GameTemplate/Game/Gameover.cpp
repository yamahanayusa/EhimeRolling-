#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "Game.h"

Gameover::Gameover()
{

}

Gameover::~Gameover()
{

}

bool Gameover::Start()
{
	//�Q�[���I�[�o�[�̉摜��ǂݍ���
	spriteRender;
	m_game = FindGO<Game>("game");
	return true;
}

void Gameover::Update()
{

}

//�`�揈��
void Gameover::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}