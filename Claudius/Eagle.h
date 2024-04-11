#pragma once
#include "Sprite.h"
#include "Transform.h"
#include "Collider.h"
#include "Color.h"
#include "ResourceManager.h"
#include "Image.h"
#include "KeyCode.h"
struct RenderManager;
class Eagle
{
public:
	Sprite sprite; // want it to render the sprite on the transform
	Transform trans;
	Collider collider;  // want it to render the collision rectangle also
	Image EagleImage;
	Color colliderColor;

	void Initialize(ResourceManager& resourseManager);
	void Update(float dt);
	void Render(RenderManager& renderManager);
	void OnKeyDown(KeyCode key);
};


