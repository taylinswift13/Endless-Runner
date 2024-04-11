#pragma once

#include "Sprite.h"
#include "Transform.h"
#include "Collider.h"
#include "Color.h"
#include "KeyCode.h"

struct RenderManager;

struct TEST_STRUCT_DELETE_BEFORE_HANDIN
{
	Sprite sprite; // want it to render the sprite on the transform
	Transform transform; 

	Collider collider;  // want it to render the collision rectangle also
	Color color {0,255,0,0}; // green

	float moveSpeed = 5;
	float rotationSpeed = 50;

	void Update(float dt);
	void Render(RenderManager& renderManager);
	void OnKeyDown(KeyCode key);
};
