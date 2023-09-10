#pragma once

#include "Entity.h"
#include <SDL.h>
#include <vector>

class Game
{
public:
	Game();
	~Game();

	void Init(const char* p_title, int x, int y, int w, int h);
	void Events();
	void Update();
	void Render();
	void Quit();

	bool IsActive;

	static inline std::vector<Entity*> Entities;

private:
	void ConfirmQuit();

	SDL_Window* Window;
	SDL_Renderer* Renderer;
};