#pragma once
#include "sound/SoundSource.h"
class Player;
class BackGround;
class GameCamera;

class Game : public IGameObject
{
public:
	Game();
	~Game();
bool Start();
void Update();
void InitSky();
 Player* m_player;
 BackGround* m_backGround;
 GameCamera* m_gameCamera;
 SkyCube* m_skyCube = nullptr;
 SoundSource* nowBGM;
 int m_skyCubeType = enSkyCubeType_Day;
};

