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

	SetPosition(GetTransform().x, GetTransform().y + 1);
}
void Block::Render()
{
	// Base
	Entity::Render();
}