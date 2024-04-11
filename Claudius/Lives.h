#pragma once
#include "Sprite.h"
#include "Transform.h"
#include "Collider.h"
#include "Color.h"
#include "ResourceManager.h"
#include "Image.h"
#include "KeyCode.h"
struct RenderManager;
class Lives
{
public:
	Sprite sprite; // want it to render the sprite on the transform
	Transform trans;
	Collider collider;  // want it to render the collision rectangle also
	Image Foxlife;
	Color colliderColor;

	void Initialize(ResourceManager& resourseManager, Vector2 Position);
	void Update(float dt);
	void Render(RenderManager& renderManager);
	void OnKeyDown(KeyCode key);
};