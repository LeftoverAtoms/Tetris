#include "Game.h"

Entity::Entity()
{
	Game::Entities.push_back(this);
}
Entity::~Entity()
{
}

void Entity::Update()
{

}
void Entity::Render()
{

}

void Entity::Destroy()
{
	delete this;
}