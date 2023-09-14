#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	Entity* Blocks[4][4] = {};

public:
	Player();
	~Player();
};