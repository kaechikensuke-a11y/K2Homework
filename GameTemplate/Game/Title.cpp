#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	spriteRender.Init("Assets/modelData/title.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/come.wav");
	titleBGM = NewGO<SoundSource>(2);
	titleBGM->Init(2);
	titleBGM->Play(true);

	

	titleRender.SetText(L"EnterƒL[‚ð‰Ÿ‚µ‚Ä‚Ë");
	titleRender.SetScale(2.0f);
	titleRender.SetPosition({ -400.0f,-400.0f,0.0f });
	titleRender.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
}
Title::~Title()
{

}

void Title::Update()
{

	if (g_pad[0]->IsTrigger(enButtonStart))
	{
		

		NewGO<Game>(0, "game");
		DeleteGO(this);
		DeleteGO(titleBGM);
		
	}
}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
	titleRender.Draw(rc);
}
