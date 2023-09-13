#pragma once

#include "Entity.h"
#include "Grid.h"
#include <vector>

class Game
{
private:
	void CreateGrid();
	void ConfirmQuit();

public:
	static std::vector<Entity*> Entities;
	static Grid Level[10][20];

	static SDL_Window* Window;
	static SDL_Renderer* Renderer;

	bool IsActive;

	Game(const char* title, int x, int y, int w, int h);
	~Game();

	void Start();
	void Events();
	void Update();
	void Render();
	void Quit();
};