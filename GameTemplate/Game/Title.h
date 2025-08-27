#pragma once
#include "sound/SoundSource.h"
class Player;
class Title:public IGameObject
{
public:
	Title();
	~Title();

	void Render(RenderContext& rc);
	void Update();

	SoundSource* titleBGM;

	SpriteRender spriteRender;

	FontRender titleRender;

	int text = 2000;
};

