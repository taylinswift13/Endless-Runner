#include "HurtAnimation.h"
#include "RenderManager.h"

void HurtAnimation::Initialize(ResourceManager& resourseManager, Vector2 AnimationSource)
{
	resourseManager.LoadImageFromFile(HurtAnimationImage, "../Assets/player_hurt.png");
	sprite.SetImage(HurtAnimationImage);
	sprite.SetSource(AnimationSource.x, 0, 33, 32);
	trans.SetScale(4, 4);
	trans.SetPosition(0, 376);
}

void HurtAnimation::Update(float dt)
{
}

void HurtAnimation::Render(RenderManager& renderManager)
{
	renderManager.Render(sprite, trans);
}

void HurtAnimation::OnKeyDown(KeyCode key)
{
}
