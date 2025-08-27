#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"
#include "Player.h"

GameClear::GameClear()
{
	spriteRender.Init("Assets/modelData/gameClear.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/onemore.wav");
	clearBGM = NewGO<SoundSource>(1);
	clearBGM->Init(1);
	clearBGM->Play(true);
}

GameClear::~GameClear()
{

}

void GameClear::Update()
{
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		NewGO<Title>(0, "title");

		DeleteGO(this);
		DeleteGO(clearBGM);
	}
}

void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}