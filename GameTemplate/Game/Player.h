#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	void Move();
	void Rotation();
	void ManageState();
	void PlayAnimation();

	ModelRender m_modelRender;
	Vector3 m_position;
	enum EnAnimationClip
	{
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];
	CharacterController m_characterController;
	Vector3 m_moveSpeed;
	Quaternion rotation;
	int playerState = 0;
	int starCount;
	int jumpCount = 0;
	int coinCount = 0;

};

