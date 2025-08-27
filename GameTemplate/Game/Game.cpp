#include "stdafx.h"
#include "Game.h"
#include "BackGround.h"
#include "Player.h"
#include "GameCamera.h"
#include "Coin.h"
#include "GameClear.h"
#include "GameOver.h"
#include "nature/SkyCube.h"
Game::Game()
{
	m_player = NewGO<Player>(0, "player");

	m_backGround = NewGO<BackGround>(0);

	m_gameCamera = NewGO<GameCamera>(0,"gamecamera");

	Coin* coin1 = NewGO<Coin>(0, "coin1");
	coin1->m_position = { 0.0f,25.0f,1100.0f };

	Coin* coin2 = NewGO<Coin>(0, "coin2");
	coin2->m_position = { 0.0f, 420.0f, 2460.0f };

	Coin* coin3 = NewGO<Coin>(0, "coin3");
	coin3->m_position = { 0.0f, 740.0f, 3950.0f };

	Coin* coin4 = NewGO<Coin>(0, "coin4");
	coin4->m_position = { 0.0f, -870.0f, 4100.0f };

	Coin* coin5 = NewGO<Coin>(0, "coin5");
	coin5->m_position = { 0.0f, -380.0f, 6500.0f };

	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/gamenow.wav");
	nowBGM = NewGO<SoundSource>(4);
	nowBGM->Init(4);
	nowBGM->Play(true);
}

Game::~Game()
{
	DeleteGO(m_player);
	
	DeleteGO(m_backGround);

	DeleteGO(m_gameCamera);

	DeleteGO(nowBGM);

	DeleteGO(FindGO<Coin>("coin1"));
	DeleteGO(FindGO<Coin>("coin2"));
	DeleteGO(FindGO<Coin>("coin3"));
	DeleteGO(FindGO<Coin>("coin4"));
	DeleteGO(FindGO<Coin>("coin5"));
}

bool Game::Start()
{
	InitSky();

	return true;
}


void Game::Update()
{
	if (m_player->coinCount > 4)
	{
		GameClear* gameClear = NewGO<GameClear>(0, "gameclear");
		DeleteGO(this);

	}

	if (m_player->m_position.y < -1600.0f)
	{
		GameOver* gameOver = NewGO<GameOver>(0, "gameover");
		DeleteGO(this);
	}
}

void Game::InitSky()
{
	//現在の空を破棄。
	DeleteGO(m_skyCube);

	m_skyCube = NewGO<SkyCube>(0, "skycube");
	m_skyCube->SetType((EnSkyCubeType)m_skyCubeType);

	//環境光の計算のためのIBLテクスチャをセットする。
	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 0.1f);
}
