#include "iostream"

#include "Block.h"

Block::Block()
{
}
Block::~Block()
{
}

void Block::Update()
{
	// Base
	Entity::Update();
}
void Block::Render()
{
	// Base
	Entity::Render();
}

void Block::Destroy()
{
	// Base
	Entity::Destroy();
}