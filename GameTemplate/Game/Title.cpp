#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
	//‰æ‘œ‚ğ“Ç‚İ‚Ş
	spriteRender;
}

Title::~Title()
{

}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{

	}
}

void Title::Render(RenderContext& rc)
{
	//‰æ‘œ‚ğ•`‰æ‚·‚éB
	spriteRender.Draw(rc);
}