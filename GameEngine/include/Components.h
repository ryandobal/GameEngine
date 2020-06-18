#pragma once

#include "ECS.h"
#include <SFML\Graphics.hpp>
#include <iostream>

struct Transfrom {
public:
	ECS_DECLARE_TYPE;

	float X, Y, rotation;

	Transfrom(float x, float y)
	{
		X = x;
		Y = y;
		rotation = 0.f;
	}
};
ECS_DEFINE_TYPE(Transform);

struct Sprite {
public:
	ECS_DECLARE_TYPE;

	int width, height;
	sf::Sprite sprite;
	std::string texture; // store a string as sort of a pointer to a sprite

	Sprite(std::string spriteName) {
		texture = spriteName;
	}
};
ECS_DEFINE_TYPE(Sprite);

struct Animator {
public:
	ECS_DECLARE_TYPE;

	int spriteWidth, spriteHeight;
	int currentColumn, currentRow;
	float currentTime, nextFrameTime;

	Animator(int width, int height, float timeBetweenFrames) {
		spriteWidth = width;
		spriteHeight = height;
		currentColumn = 0;
		currentRow = 0;
		nextFrameTime = timeBetweenFrames;
		currentTime = 0;
	}
};
ECS_DEFINE_TYPE(Animator);