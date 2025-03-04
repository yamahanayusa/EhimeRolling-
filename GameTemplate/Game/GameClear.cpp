#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"

GameClear::GameClear()
{

}

GameClear::~GameClear()
{

}

bool GameClear::Start()
{
	spriteRender;
	m_game = FindGO<Game>("game");
	return true;
}

//更新処理
void GameClear::Update()
{
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトルのオブジェクトをつくる
		NewGO<Title>(0, "title");
		//自身を削除する
		DeleteGO(this);
		DeleteGO(m_game);
	}
}

//描画処理
void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}