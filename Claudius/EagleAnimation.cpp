#include "EagleAnimation.h"
#include "RenderManager.h"
void EagleAnimation::Initialize(ResourceManager& resourseManager, Vector2 AnimationSource)
{
	resourseManager.LoadImageFromFile(EagleAnimationImage, "../Assets/Eagle.png");
	sprite.SetImage(EagleAnimationImage);
	sprite.SetSource(AnimationSource.x, 0, 33, 32);
	trans.SetScale(1.2, 1.2);	
	trans.SetPosition(0, 376);
}

void EagleAnimation::Update(float dt)
{
}

void EagleAnimation::Render(RenderManager& renderManager)
{
	renderManager.Render(sprite, trans);
}

void EagleAnimation::OnKeyDown(KeyCode key)
{
}
