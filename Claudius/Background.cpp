#include "background.h"
#include "RenderManager.h"
#include<iostream>
void Background::Initialize(ResourceManager& resourseManager, std::string FileSource,float speed,Vector2 position)
{
	resourseManager.LoadImageFromFile(backgroundImage, FileSource);
	sprite.SetImage(backgroundImage);
	sprite.SetSource(0, 0, 300, 200);
	trans.SetScale(3,3);
	trans.SetPosition(position.x, position.y);
	this->speed = speed;
}

void Background::Update(float dt)
{
	//scolling
	trans.position.x -= dt * speed;
	//shaking
}

void Background::Render(RenderManager& renderManager)
{
	renderManager.Render(sprite, trans);
}

void Background::Shake(int extent)
{
	shaketime++;
	if (shaketime > 10)
	{
		trans.SetPosition(-extent, extent);
		if (shaketime > 20)
		{
			trans.SetPosition(extent, -extent);
			shaketime = 0;
		}
	}
}


