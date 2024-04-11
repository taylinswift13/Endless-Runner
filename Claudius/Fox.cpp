#include "Fox.h"
#include "RenderManager.h"
void Fox::Initialize(ResourceManager& resourseManager)
{
	resourseManager.LoadImageFromFile(foxImage, "../Assets/player_run.png");
	sprite.SetImage(foxImage);
	sprite.SetSource(0, 0, 0, 0);
	trans.SetScale(4,4);
	trans.SetPosition(400, 376);

	collider.SetPosition((int)trans.position.x+30, (int)trans.position.y+35);
	collider.SetSize(70,80 );
}

void Fox::Update(float dt)
{
	collider.SetPosition(trans.position.x+30, trans.position.y+35);
	Move(dt);
}

void Fox::Render(RenderManager& renderManager)
{
	renderManager.Render(sprite, trans);
	//renderManager.Render(collider.rect, colliderColor);
}

void Fox::OnKeyDown(KeyCode key)
{
	if (key == KeyCode::SPACE&&JumpingUp==false&&JumpingDown==false )
	{
		JumpingUp=true;//JUMP
	}
}

void Fox::OnKeyUp(KeyCode key)
{
}

void Fox::Move(float dt)
{
	if (JumpingUp == true)
	{//keep moving it not reach the edge
		if (Accumulated_Distace <= 160)
		{
			trans.position.y -= speed * dt*3;
			Accumulated_Distace += speed * dt*3;
		}
		else if (Accumulated_Distace >= 160)
		{
			JumpingUp = false;
			JumpingDown = true;
		}
	}
	else if(JumpingDown==true)
	{
		trans.position.y += speed * dt*3;
		Accumulated_Distace -= speed * dt*3;
		if (Accumulated_Distace<=0)
		{
			JumpingDown = false;
		}
	}
}
