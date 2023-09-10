#pragma once

#include "Entity.h"

class Block : public Entity
{
public:
	Block();
	~Block();

	void Update() override;
	void Render() override;
};