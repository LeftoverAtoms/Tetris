#include "Game.h"
#include <iostream>
#include <SDL_image.h>
#include <SDL.h>

uint8_t Entity::IDCount = 0;

Entity::Entity()
{
	Game::Entities.push_back(this);

	ID = IDCount++;
}
Entity::~Entity()
{
	// Messy and error prone
	/*for (int i = 0; i < Game::Entities.size(); i++)
	{
		if (ID == Game::Entities[i]->ID)
		{
			Game::Entities.erase(Game::Entities.begin(), Game::Entities.begin() + i);
		}
	}*/
}
void Entity::Start() {}
void Entity::Update() {}

void Entity::Render()
{
	SDL_Rect uv = { 0, 0, Transform.w, Transform.h };
	SDL_Rect in = { Transform.x, Transform.y, Transform.w, Transform.h };

	if (SDL_RenderCopy(Game::Renderer, Sprite, &uv, &in) != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}
}

void Entity::SetTexture(const char* filePath)
{
	SDL_Texture* texture = nullptr;

	texture = IMG_LoadTexture(Game::Renderer, filePath);
	if (texture == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	SDL_Rect out;

	if (SDL_QueryTexture(texture, nullptr, nullptr, &out.w, &out.h) != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	Transform.w = out.w;
	Transform.h = out.h;

	Sprite = texture;
}
void Entity::SetPosition(int x, int y)
{
	Transform.x = x;
	Transform.y = y;
}
void Entity::SetScale(int w, int h)
{
	Transform.w = w;
	Transform.h = h;
}