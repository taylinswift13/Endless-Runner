#pragma once
#include "Sprite.h"
#include "Transform.h"
#include "Collider.h"
#include "Color.h"
#include "ResourceManager.h"
#include "Image.h"
#include "KeyCode.h"
#include"background.h"
struct RenderManager;
class Fox
{
public:
	Sprite sprite; // want it to render the sprite on the transform
	Transform trans;
	Collider collider;  // want it to render the collision rectangle also
	Image foxImage;
	Color colliderColor;
	float speed=65;
	float Accumulated_Distace=0;
	int direction=0;
	bool JumpingUp=false;
	bool JumpingDown=false;
	bool Hurting = false;

	void Initialize(ResourceManager& resourseManager);
	void Update(float dt);
	void Render(RenderManager& renderManager);
	void OnKeyDown(KeyCode key);
	void OnKeyUp(KeyCode key);
	void Move(float dt);
};