#pragma once
#include <SDL.h>

class Entity
{
public:
	Entity();
	~Entity();

	virtual void Update();
	virtual void Render();

	SDL_Rect GetTransform();

	void SetTexture(const char* filePath);
	void SetPosition(int x, int y);
	void SetScale(int value);

private:
	static inline int IDCount;

	int ID;

	SDL_Texture* Sprite;
	SDL_Rect Transform;
};