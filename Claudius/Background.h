#pragma once
#include<iostream>
#include "Sprite.h"
#include "Transform.h"
#include "Collider.h"
#include "Color.h"
#include "ResourceManager.h"
#include "Image.h"
struct RenderManager;
class Background
{
public:
	float speed=0;
	float shaketime = 0;
	Sprite sprite; // want it to render the sprite on the transform
	Transform trans;
	Collider collider;  // want it to render the collision rectangle also
	Image backgroundImage;
	void Initialize(ResourceManager& resourseManager,std::string FileSource,float speed,Vector2 position);
	void Update(float dt);
	void Render(RenderManager& renderManager);
	void Shake(int extent);
};
