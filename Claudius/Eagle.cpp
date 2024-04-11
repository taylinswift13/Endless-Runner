#include "Eagle.h"
#include "RenderManager.h"
void Eagle::Initialize(ResourceManager& resourseManager)
{
	resourseManager.LoadImageFromFile(EagleImage, "../Assets/Eagle.png");
	sprite.SetImage(EagleImage);
	sprite.SetSource(0, 0, 35, 32);
	trans.SetScale(1.2, 1.2);
	trans.SetPosition(1300, 460);
	collider.SetPosition((int)trans.position.x, (int)trans.position.y);
	collider.SetSize(30, 30);
}

void Eagle::Update(float dt)
{
	collider.SetPosition(trans.position.x+5, trans.position.y+5 );
	trans.position.x -= 100 * dt;
}

void Eagle::Render(RenderManager& renderManager)
{
	//renderManager.Render(sprite, trans);
	//renderManager.Render(collider.rect, colliderColor);
}

void Eagle::OnKeyDown(KeyCode key)
{
}
