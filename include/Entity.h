#pragma once
#include <SDL.h>

class Entity
{
public:
	Entity();
	~Entity();

	virtual void Update();
	virtual void Render();

	void SetSprite(const char* filePath);

	SDL_Rect GetTransform();

	void SetPosition(int x, int y);
	void SetScale(int value);

private:
	static inline int IDCount;

	int ID;

	SDL_Texture* Sprite;
	SDL_Rect Transform;
};