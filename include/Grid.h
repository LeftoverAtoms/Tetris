#pragma once

#include "Entity.h"

class Grid : public Entity
{
private:
	Entity* Entity;

public:
	Grid();
	~Grid();
};