#include "Block.h"

Block::Block() {}
Block::~Block() {}

void Block::Start() {}
void Block::Update()
{
	Entity::Update(); // Copy code from base class

	SDL_Rect newPos = GetTransform();
	newPos.y++;

	SetPosition(newPos.x, newPos.y);
}