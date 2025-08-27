#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"

GameOver::GameOver()
{
	m_spriteRender.Init("Assets/modelData/gameOver.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/warau.wav");
	overBGM = NewGO<SoundSource>(3);
	overBGM->Init(3);
	overBGM->Play(true);
}

GameOver::~GameOver()
{

}

void GameOver::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
		DeleteGO(overBGM);
	}
}

void GameOver::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}
