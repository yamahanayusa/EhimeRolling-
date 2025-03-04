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
	//ゲームオーバーの画像を読み込む
	spriteRender;
	m_game = FindGO<Game>("game");
	return true;
}

void Gameover::Update()
{

}

//描画処理
void Gameover::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}