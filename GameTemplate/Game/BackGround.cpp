#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	m_GroundRender.Init("Assets/ReGame Stage/stage.tkm");
	m_GroundRender.Update();
	physicsStaticObject.CreateFromModel(m_GroundRender.GetModel(), m_GroundRender.GetModel().GetWorldMatrix());
}

BackGround:: ~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	m_GroundRender.Draw(rc);
}
