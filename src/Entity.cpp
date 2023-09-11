#include <iostream>

#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>

Entity::Entity()
{
	Game::Entities.push_back(this);

	ID = IDCount++;
	Sprite = nullptr;
	Transform = SDL_Rect();
}
Entity::~Entity()
{
	for (int i = 0; i < Game::Entities.size(); i++)
	{
		if (ID == Game::Entities[i]->ID)
		{
			Game::Entities.erase(Game::Entities.begin(), Game::Entities.begin() + i);
		}
	}
}

void Entity::Update() {}
void Entity::Render()
{
	SDL_Rect uv =
	{
		uv.x = 0,
		uv.y = 0,
		uv.w = Transform.w,
		uv.h = Transform.h
	};

	SDL_RenderCopy(Game::Renderer, Sprite, &uv, &Transform);
}

void Entity::SetSprite(const char* filePath)
{
	SDL_Texture* texture = nullptr;

	texture = IMG_LoadTexture(Game::Renderer, filePath);
	if (texture == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	if (SDL_QueryTexture(texture, nullptr, nullptr, &Transform.w, &Transform.h) != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	Sprite = texture;
}

SDL_Rect Entity::GetTransform()
{
	return Transform;
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