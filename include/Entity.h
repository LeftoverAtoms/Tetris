#pragma once
#include <SDL.h>

class Entity
{
public:
	Entity();
	~Entity();

	virtual void Update();
	virtual void Render();

	SDL_Texture* Sprite;

private:
	int ID;
	static inline int IDCount;
};