#include "JumpingAnimation.h"
#include "RenderManager.h"
void JumpingAnimation::Initialize(ResourceManager& resourseManager, Vector2 AnimationSource)
{
	resourseManager.LoadImageFromFile(JumpingAnimationImage, "../Assets/player_jump.png");
	sprite.SetImage(JumpingAnimationImage);
	sprite.SetSource(AnimationSource.x, 0, 33, 32);
	trans.SetScale(4, 4);
	trans.SetPosition(0, 376);
}

void JumpingAnimation::Update(float dt)
{
}

void JumpingAnimation::Render(RenderManager& renderManager)
{
	renderManager.Render(sprite, trans);
}

void JumpingAnimation::OnKeyDown(KeyCode key)
{
}
