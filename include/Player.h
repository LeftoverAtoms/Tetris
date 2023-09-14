#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	Entity* Blocks[5] = {};

public:
	Player();
	~Player();
};