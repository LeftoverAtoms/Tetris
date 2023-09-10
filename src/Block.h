#pragma once

#include "Entity.h"

class Block : Entity
{
public:
	Block();
	~Block();

	void Update() override;
	void Render() override;

	void Destroy() override;
};