#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	Entity* Blocks[4][4] = {};

public:
	static Player* Instance;

	Player();
	~Player();

	void Update() override;

	void ParseBlock(Block block);
};