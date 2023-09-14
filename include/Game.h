#pragma once

#include "Entity.h"
#include <vector>

class Game
{
private:
	void CreateGrid(const char* filePath, int scale);
	void ConfirmQuit();

public:
	static std::vector<Entity*> Entities;
	static Entity* Grid[10][20];

	static SDL_Renderer* Renderer;
	static SDL_Window* Window;

	bool IsActive;

	Game(const char* title, int x, int y, int w, int h);
	~Game();

	void Start();
	void Events();
	void Update();
	void Render();
	void Quit();
};