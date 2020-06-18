#pragma once

#include "ECS.h"
// #include "Engine.h"
#include "Components.h"

class AnimationSystem : public ECS::EntitySystem
{
	AnimationSystem();
	~AnimationSystem();

	void tick(ECS::World* world, float deltaTime) override;
};

