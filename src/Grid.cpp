#include "Grid.h"

Grid::Grid()
{
	Transform = SDL_Rect();
	Full = false;
}
Grid::~Grid() {}

void Grid::SetTransform(SDL_Rect transform)
{
	Transform = transform;
}