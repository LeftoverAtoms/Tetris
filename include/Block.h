#pragma once

#include "Entity.h"

class Block : public Entity
{
public:
	Block();
	~Block();

	void Start() override;
	void Update() override;
};