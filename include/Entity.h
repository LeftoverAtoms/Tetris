#pragma once

#include <SDL.h>

class Entity
{
private:
	static int IDCount;

	SDL_Texture* Sprite = nullptr;
	SDL_Rect Transform = {};
	SDL_Rect UV = {};

public:
	int ID;

	Entity();
	~Entity();
	virtual void Start();
	virtual void Update();

	void Render();

	SDL_Rect GetTransform();

	void SetTexture(const char* filePath);
	void SetPosition(int x, int y);
	void SetScale(int value);
};