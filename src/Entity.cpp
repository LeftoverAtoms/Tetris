#include "iostream"

#include "Game.h"

Entity::Entity()
{
	Game::Entities.push_back(this);

	ID = IDCount++;

	std::cout << ID << std::endl;
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
void Entity::Render() {}

void Entity::Destroy()
{
	delete(this);
}