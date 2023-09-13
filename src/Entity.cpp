#include "Game.h"
#include <iostream>
#include <SDL_image.h>
#include <SDL.h>

int Entity::IDCount = 0;

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
	if (SDL_RenderCopy(Game::Renderer, Sprite, &UV, &Transform) != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}
}

SDL_Rect Entity::GetTransform()
{
	return Transform;
}

void Entity::SetTexture(const char* filePath)
{
	SDL_Texture* texture = nullptr;

	texture = IMG_LoadTexture(Game::Renderer, filePath);
	if (texture == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	if (SDL_QueryTexture(texture, nullptr, nullptr, &UV.w, &UV.h) != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	// Hack
	Transform.w = UV.w;
	Transform.h = UV.h;

	Sprite = texture;
}
void Entity::SetPosition(int x, int y)
{
	Transform.x = x;
	Transform.y = y;
}
void Entity::SetScale(int value)
{
	Transform.w = value;
	Transform.h = value;
}