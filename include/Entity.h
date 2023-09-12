#pragma once
#include <SDL.h>

class Entity
{
public:
	int ID;

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

	SDL_Texture* Sprite;

	SDL_Rect UV;
	SDL_Rect Transform;
};