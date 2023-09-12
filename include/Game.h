#pragma once

#include "Entity.h"
#include "Grid.h"
#include <vector>

class Game
{
public:
	static std::vector<Entity*> Entities;
	static Grid Level[10][20];

	static SDL_Window* Window;
	static SDL_Renderer* Renderer;

	bool IsActive;

	Game();
	~Game();

	void Init(const char* p_title, int x, int y, int w, int h);

	void CreateGrid();

	void Events();
	void Update();
	void Render();
	void Quit();

private:
	void ConfirmQuit();
};