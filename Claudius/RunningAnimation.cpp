#include "RunningAnimation.h"
#include "RenderManager.h"
void RunningAnimation::Initialize(ResourceManager& resourseManager,Vector2 AnimationSource)
{
	resourseManager.LoadImageFromFile(RunningAnimationImage, "../Assets/player_run.png");
	sprite.SetImage(RunningAnimationImage);
	sprite.SetSource(AnimationSource.x, 0, 33, 32);
	trans.SetScale(4, 4);
	trans.SetPosition(0, 376);
}

void RunningAnimation::Update(float dt)
{

}

void RunningAnimation::Render(RenderManager& renderManager)
{
	renderManager.Render(sprite, trans);
}

void RunningAnimation::OnKeyDown(KeyCode key)
{

}
