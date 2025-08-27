#include "stdafx.h"
#include "Coin.h"
#include "Player.h"
#include "sound/SoundEngine.h"

Coin::Coin()
{
	m_modelRender.Init("Assets/modelData/Coin.tkm");

	player = FindGO<Player>("player");


}

Coin::~Coin()
{

}

void Coin::Update()
{
	Move();

	Rotation();

	m_modelRender.Update();

	Vector3 diff = player->m_position - m_position;
	if (diff.Length() <= 50.0f)
	{
		player->coinCount += 1;
		DeleteGO(this);
		g_soundEngine->ResistWaveFileBank(0, "Assets/sound/born.wav");
		CoinBGM = NewGO<SoundSource>(0);
		CoinBGM->Init(0);
		CoinBGM->Play(false);
	}
}

void Coin::Move()
{
	m_modelRender.SetPosition(m_position);
}

void Coin::Rotation()
{
	m_rotation.AddRotationDegY(5.0);
	m_modelRender.SetRotation(m_rotation);
}

void Coin::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}