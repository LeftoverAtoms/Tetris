#pragma once
#include <SDL.h>

class Grid
{
public:
	Grid();
	~Grid();

	void SetTransform(SDL_Rect transform);

private:
	SDL_Rect Transform;
	bool Full;
};