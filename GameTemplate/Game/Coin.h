#pragma once
#include "sound/SoundSource.h"
class Player;
class Coin : public IGameObject
{
public:
	Coin();
	~Coin();

	void Update();

	void Render(RenderContext& rc);
	void Move();

	void Rotation();

	SoundSource* CoinBGM;

	ModelRender m_modelRender;
	Vector3 m_position;
	Quaternion m_rotation;
	Player* player;
};

