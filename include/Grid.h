#pragma once
#include <Entity.h>
#include <SDL.h>

class Grid : public Entity
{
public:
	Grid();
	~Grid();

private:
	bool Full;
};