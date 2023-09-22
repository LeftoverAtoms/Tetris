#pragma once

#include <SDL.h>
#include "Transform.h"

class Entity
{
private:
	static uint8_t IDCount;

	uint8_t ID;
	SDL_Texture* Sprite = nullptr;
	SDL_Rect UV = { 0, 0, 0, 0 };

public:
	bool Active = true;
	Transform Transform = { 0, 0, 0, 0 };

	Entity();
	~Entity();
	virtual void Start();
	virtual void Update();

	void Render();

	void SetTexture(const char* filePath);
	void SetPosition(int x, int y);
	void SetScale(int w, int h);
};