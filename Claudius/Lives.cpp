#include "Lives.h"
#include "RenderManager.h"
void Lives::Initialize(ResourceManager& resourseManager, Vector2 Position)
{
	resourseManager.LoadImageFromFile(Foxlife, "../Assets/player_idle.png");
	sprite.SetImage(Foxlife);
	sprite.SetSource(0, 0, 33, 32);
	trans.SetScale(1, 1);
	trans.SetPosition(Position.x, 0);
}

void Lives::Update(float dt)
{
}

void Lives::Render(RenderManager& renderManager)
{
	renderManager.Render(sprite, trans);
}

void Lives::OnKeyDown(KeyCode key)
{
}
