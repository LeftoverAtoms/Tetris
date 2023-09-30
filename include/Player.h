#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	Entity* Blocks[4][4] = {};
	int Rotation = 0;

public:
	static Player* Instance;

	Player();
	~Player();

	void Update() override;

	void ParseBlock(Block block);
};